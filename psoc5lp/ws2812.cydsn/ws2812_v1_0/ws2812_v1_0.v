
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 04/13/2021 at 11:09
// Component: ws2812_v1_0
module ws2812_v1_0 (
	output  ws2812,
    output  irq,
	input   clk,
	input   rst
);

    localparam IDLE = 3'h0;
    localparam WS2812_RESET = 3'h1;
    localparam LOAD_A0 = 3'h2;
    localparam CHECK_BIT = 3'h3;
    localparam SEND_BIT = 3'h4;
    localparam DEC_BIT_CNT = 3'h5;
    localparam SHIFT_DATA = 3'h6;
    localparam NOP = 3'h7;

    reg [2:0]state;//Адрес команды
    reg out;//Регистр выходного сигнала
    reg send_tic;//Регистр дополнительного такта
    wire fifo_empty;//Флаг пустого FIFO
    wire send_bit;//значение отправляемого бита
    wire end_ws2812_reset;//Флаг равенства 0xFF регистра A1
    wire z_count_bit;//Флаг равенства 0 счетчика бит
    assign irq=fifo_empty;//Присваиваем выходу прерывания флаг пустого FIFO
    assign ws2812=out;//Присваиваем выходной сигнал регистру выходного сигнала

	always @(posedge clk or posedge rst )//

	begin
		if (rst)
		begin       // Асинхронный сброс
			state <= IDLE;
            out<=1'b1;
		end
		else
		begin
			case (state)
				
			IDLE://Ожидание поступления данных в FIFO
			begin
				if(fifo_empty==1'b0)
				begin
					state <= WS2812_RESET;//Если данные в FIFO поступили, 
                    out<=1'b0;//переходим к команде формирования импульса сброса, выходной сигнал в 0
				end
				else
				begin
                    out<=1'b1;//Если данных в FIFO нет, выходной сигнал в 1
                end
			end
					
			WS2812_RESET://Формирование импульса сброса
			begin
                if(end_ws2812_reset)//Ждем равенства 0xFF регистра A1
                begin
                    state <= LOAD_A0;//Если A1=0xFF, переходим к команде загрузки данных из FIFO
                    out<=1'b1;//Выход в 1
                end
			end
			LOAD_A0://Загрузка байта из FIFO
			begin
                state <= CHECK_BIT;//Переходим к команде проверки значения выводимого бита
			end
			CHECK_BIT://Команда проверки значения выводимого бита
			begin
                send_tic <= 1'b0;//Обнуляем регистр дополнительного такта
                state <= SEND_BIT;//Переходим к команде отправки бита данных
                if(send_bit==1'b0)
                begin
                    out <= 1'b0;//Если выводимый бит 0, устанавливаем выход в 0
                end
			end
			SEND_BIT://Команда отправки бита данных
			begin
                if(send_tic)//Если дополнительный такт уже был
                begin
                    state <= DEC_BIT_CNT;//Переходим к команде декремента счетчика бит
                    out <= 1'b0;//Устанавливаем выходной сигнал в 0
                end
                else
                begin
                    send_tic <= 1'b1;//Если дополнительного такта не было, устанавливаем флаг дополнительного такта
                end
			end
			DEC_BIT_CNT://Команда декремента счетчика бит
			begin
                state <= SHIFT_DATA;//Переходим к команде сдвига выводимого байта влево
			end
			SHIFT_DATA://Команда сдвига выводимого байта влево
			begin
                out<=1'b1;//Выходной сигнал в 1
                if(z_count_bit)//Если счетчик выведенных бит равен 0
                begin
                    if(fifo_empty == 1'b0)//Если FIFO не пуст
                    begin
                        state <= LOAD_A0;//Переходим к загрузке нового байта
                    end
                    else
                    begin
                        state <= IDLE;//Если пуст переходим в режим ожидания прихода данных в FIFO
                    end
                end
                else
                begin
                    state <= NOP;//Если счетчик бит не равен 0, переходим к формированию дополнительного такта
                end
			end
			NOP://Команда дополнительного такта
			begin
                state <= CHECK_BIT;//Переходим к команде проверки значения выводимого бита
			end
		endcase
		end
	end	

cy_psoc3_dp8 #(.d0_init_a(8'h80), .d1_init_a(8'h08), 
.cy_dpconfig_a(
{
    `CS_ALU_OP__XOR, `CS_SRCA_A1, `CS_SRCB_A1,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM0:   IDLE OUT=1 A1=A1^A1*/
    `CS_ALU_OP__INC, `CS_SRCA_A1, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM1:   RESET WS2812 OUT=0 A1--*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___F0, `CS_A1_SRC___D1,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM2:   F0->A0 D1->A1*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM3:   CHECK BIT*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM4:   SEND BIT*/
    `CS_ALU_OP__DEC, `CS_SRCA_A1, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM5:   DEC BIT CNT OUT=0*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP___SL, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM6:   A0=A0<<1*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM7:   NOP*/
    8'hFF, 8'h00,  /*CFG9:    */
    8'hFF, 8'h80,  /*CFG11-10:    */
    `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_ARITH,
    `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_ENBL,
    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
    `SC_SI_A_DEFSI, /*CFG13-12:    */
    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
    `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
    `SC_FB_NOCHN, `SC_CMP1_NOCHN,
    `SC_CMP0_NOCHN, /*CFG15-14:    */
    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
    `SC_WRK16CAT_DSBL /*CFG17-16:    */
}
)) udb8(
        /*  input                   */  .reset(rst),//Входной сигнал сброса
        /*  input                   */  .clk(clk),//Входной тактовый сигнал
        /*  input   [02:00]         */  .cs_addr(state),//Регистр адреса команды DataPath
        /*  input                   */  .route_si(1'b0),
        /*  input                   */  .route_ci(1'b0),
        /*  input                   */  .f0_load(1'b0),
        /*  input                   */  .f1_load(1'b0),
        /*  input                   */  .d0_load(1'b0),
        /*  input                   */  .d1_load(1'b0),
        /*  output                  */  .ce0(send_bit),//Значение отправляемого бита
        /*  output                  */  .cl0(),
        /*  output                  */  .z0(),
        /*  output                  */  .ff0(),
        /*  output                  */  .ce1(),
        /*  output                  */  .cl1(),
        /*  output                  */  .z1(z_count_bit),//Флаг равенству 0 счетчика бит
        /*  output                  */  .ff1(end_ws2812_reset),//Флаг равеству 0xFF регистра A1
        /*  output                  */  .ov_msb(),
        /*  output                  */  .co_msb(),
        /*  output                  */  .cmsb(),
        /*  output                  */  .so(),
        /*  output                  */  .f0_bus_stat(),
        /*  output                  */  .f0_blk_stat(fifo_empty),//Флаг пустого FIFO
        /*  output                  */  .f1_bus_stat(),
        /*  output                  */  .f1_blk_stat()
);
//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line




