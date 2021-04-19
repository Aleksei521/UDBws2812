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
#include "cytypes.h"
#include "color.h"
#define FONT_WIDTH 8
#define FONT_HIGH 10
uint8 text[]={7,0,3,4,4,5,0,1,2,6};
uint32 color[]={RED*2,BLUE*2,BLUE*2,BLUE*2,BLUE*2,BLUE*2,BLUE|GREEN,BLUE|GREEN,BLUE|GREEN,BLUE|GREEN};
const uint8 font[9][10] = {{ /* code 0 */
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x7E, // .######.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x00  // ........
},{ /* code 1 */
  0x00, // ........
  0x00, // ........
  0x3C, // ..####..
  0x06, // .....##.
  0x06, // .....##.
  0x3E, // ..#####.
  0x66, // .##..##.
  0x66, // .##..##.
  0x3E, // ..#####.
  0x00  // ........
},{ /* code 2 */
  0x60, // .##.....
  0x60, // .##.....
  0x7C, // .#####..
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x7C, // .#####..
  0x00  // ........
},{ /* code 3 */
  0x00, // ........
  0x00, // ........
  0x3C, // ..####..
  0x66, // .##..##.
  0x66, // .##..##.
  0x7E, // .######.
  0x60, // .##.....
  0x60, // .##.....
  0x3C, // ..####..
  0x00  // ........
},{ /* code 4 */
  0x78, // .####...
  0x18, // ...##...
  0x18, // ...##...
  0x18, // ...##...
  0x18, // ...##...
  0x18, // ...##...
  0x18, // ...##...
  0x18, // ...##...
  0x7E, // .######.
  0x00  // ........
},{ /* code 5 */
  0x00, // ........
  0x00, // ........
  0x3C, // ..####..
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x66, // .##..##.
  0x3C, // ..####..
  0x00  // ........
},{ /* code 6 */
  0x00, // ........
  0x00, // ........
  0x66, // .##..##.
  0x6E, // .##.###.
  0x70, // .###....
  0x60, // .##.....
  0x60, // .##.....
  0x60, // .##.....
  0x60, // .##.....
  0x00  // ........
},{ /* code 7 */
  0x00, // ........
  0x00, // ........
  0x36, // ..##.##.
  0x7F, // .#######
  0x7F, // .#######
  0x3E, // ..#####.
  0x1C, // ...###..
  0x08, // ....#...
  0x00, // ........
  0x00  // ........
},{ /* code 8 */
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00, // ........
  0x00  // ........
}};

/* [] END OF FILE */