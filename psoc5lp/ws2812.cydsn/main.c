/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "font.h"
#include "color.h"

#define LED_WIDTH 10
#define LED_HIGH 10
#define TIMER_ISR_TC_MASK 0x8

struct {
    uint8 buffer[LED_WIDTH*LED_HIGH*3];
    uint8 draw_buffer[LED_WIDTH*LED_HIGH*3];
    volatile uint8 *buffer_ptr;
    volatile uint32 wait_tx :1;
} ws2812_struct;

void writePixelRGB(uint8 x, uint8 y, uint32 color);
void fillScreen(uint32 color);
void copyBuffer(uint32 *src, uint32 *dst, uint32 num);
void writeChar(uint8 column_display, uint8 column_char, uint8 id_char, uint32 color, uint32 background_color);
void scrolStr(uint8 *str, uint16 len, uint32 *char_color, uint32 background_color);

CY_ISR_PROTO(WS2812_HANDLER);
CY_ISR_PROTO(TIMER100HZ_HANDLER);

CY_ISR(TIMER100HZ_HANDLER)
{
    if(Timer_1_STATUS & TIMER_ISR_TC_MASK)
    {
        isr_ws2812_Enable();
        ws2812_struct.wait_tx=0;
    }
        
}
CY_ISR(WS2812_HANDLER)
{
    for(int i=0; i<ws2812_1_FIFO_LEVELS;i++)
    {
        ws2812_1_data_fifo=*ws2812_struct.buffer_ptr;
        if(ws2812_struct.buffer_ptr==&ws2812_struct.buffer[sizeof(ws2812_struct.buffer)-1])
        {
            isr_ws2812_Disable();
            ws2812_struct.wait_tx=1;
            ws2812_struct.buffer_ptr=ws2812_struct.buffer;
            break;
        }
        else
        {
            ws2812_struct.buffer_ptr++;
        }
    }
}

int main(void)
{
    ws2812_struct.buffer_ptr=ws2812_struct.buffer;
    fillScreen(0);
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_1_Start();
    ws2812_1_Start();
    isr_ws2812_StartEx(WS2812_HANDLER);
    isr_timer_StartEx(TIMER100HZ_HANDLER);
    
    uint16 delay=0;
    for(;;)
    {
        if((delay++)==20)
        {
            delay=0;
            scrolStr(text, sizeof(text), color , BACKGROUND);
        }
        while(ws2812_struct.wait_tx==0);
        ws2812_struct.wait_tx=0;
        copyBuffer((uint32*)ws2812_struct.draw_buffer,(uint32*)ws2812_struct.buffer,sizeof(ws2812_struct.buffer)/4);            
    }
}
void scrolStr(uint8 *str, uint16 len, uint32 *char_color, uint32 background_color)
{
    static uint16 begin_position=LED_WIDTH-1;
    static uint16 index_position=0;
    static uint16 point_position=0;
    for(int16 i=0;i<((LED_WIDTH-begin_position-1)/FONT_WIDTH)+1;i++)
    {
        uint8 idx_char=index_position+i;
        if(idx_char==len)
            idx_char=0;
        writeChar(i==0 ? begin_position : begin_position+FONT_WIDTH-point_position+FONT_WIDTH*(i-1),\
            i==0 ? point_position : 0,\
            str[idx_char],\
            char_color[idx_char],\
            background_color);
    }
    if(begin_position!=0)
        begin_position--;
    else
    {
        if(point_position==(FONT_WIDTH-1))
        {
            point_position=0;
            if(index_position==len-1)
                index_position=0;
            else
                index_position++;
        }
        else
            point_position++;
    }
}
void copyBuffer(uint32 *src, uint32 *dst, uint32 num)
{
    for(uint32 i=0;i<num;i++)
        *(dst++)=*(src++);
}
void writeChar(uint8 column_display, uint8 column_char, uint8 id_char, uint32 char_color, uint32 background_color)
{
    uint8 shift;
    for(int8 j=LED_HIGH-1;j>=0;j--)
    {
        shift=0x80>>column_char;
        for(uint8 i=column_display;i<(column_display+FONT_WIDTH) && i<LED_WIDTH;i++)
        {
            if(font[id_char][j]&shift)
                writePixelRGB(i,FONT_HIGH-j-1,char_color);
            else
                writePixelRGB(i,FONT_HIGH-j-1,background_color);
            shift >>=1;
        }
    }
}
void writePixelRGB(uint8 x, uint8 y, uint32 color)
{
    uint16 point=(LED_HIGH*(LED_WIDTH-x-1)+y)*3;
    ws2812_struct.draw_buffer[point++]=(uint8)(color>>16);
    ws2812_struct.draw_buffer[point++]=(uint8)(color>>8);
    ws2812_struct.draw_buffer[point]=(uint8)color;
}
void fillScreen(uint32 color)
{
    for(uint16 i=0;i<LED_WIDTH*LED_HIGH*3;i+=3)
    {
        ws2812_struct.draw_buffer[i]=(uint8)(color>>16);
        ws2812_struct.draw_buffer[i+1]=(uint8)(color>>8);
        ws2812_struct.draw_buffer[i+2]=(uint8)color;
    }
}
/* [] END OF FILE */

