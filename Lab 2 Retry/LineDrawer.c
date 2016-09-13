#include <stdint.h>
#include <stdio.h>
#include "LineDrawer.h"
#include "ST7735.h"


//*************ST7735_Line********************************************
//  Draws one line on the ST7735 color LCD
//  Inputs: (x1,y1) is the start point
//          (x2,y2) is the end point
// x1,x2 arehorizontal positions, columns from the left edge
//               must be less than 128
//               0 is on the left, 126 is near the right
// y1,y2 arevertical positions, rows from the top edge
//               must be less than 160	
//               159 is near the wires, 0 is the side opposite the wires
//        color 16-bit color, which can be produced by ST7735_Color565()
// Output: none
void ST7735_Line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color){
	
	if(y1 > y2){																				// If y1 > y2, switch the y-coordinates.
			uint32_t temp = y1;
			y1 = y2;
			y2 = temp;
	}
	if(x1 > x2){																				// Same with x-coordinates
			uint32_t temp = x1;
			x1 = x2;
			x2 = temp;
	}
	if(x1 == x2){																				// If line is a vertical line
			for(int i = y1; i <= y2; i++){
					ST7735_DrawPixel(x1, i, color);
			}
			return;
	}	
	if(y1 == y2){																				// If line is a horizontal line
			for(int i = x1; i <= x2; i++){
					ST7735_DrawPixel(i, y1, color);
			}
			return;
	}	
	
	uint32_t deltaX = x2 - x1;													// Otherwise, draw line using Bresenham's line algorithm
	uint32_t deltaY = y2 - y1;
	uint32_t currentY = y1;
//	uint32_t slopeY = (deltaY/deltaX);
//	float Error = 0.0;
//	float deltaError = (deltaY/deltaX);
	for(int i = x1; i <= x2; i++){
			ST7735_DrawPixel(i, currentY, color);
			currentY = (i*deltaY)/deltaX;
/*			Error = Error + deltaError;
			if(Error >= 2.0){
					currentY += 2;
					Error -= 1.0;
			}
			if(Error >= 1.0 && Error < 2.0){
					currentY += 1;
					Error -= 1.0;
			}
*/
	}	
}
