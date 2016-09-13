#include "Graph.h"
#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"










void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, int32_t minY, int32_t maxY){
	ST7735_InitR(INITR_REDTAB);
	ST7735_OutString(title);
	ST7735_PlotClear(minY, maxY);
};




void ST7735_XYplot(uint32_t num, uint32_t bufX[], uint32_t bufY[], uint32_t xmin, uint32_t xmax, uint32_t ymin, uint32_t ymax){
	for(int i = 0; i < num; i++){
		int16_t x = (((bufX[i] - xmin)*127))/(xmax - xmin);									//scales x from 0 to 127
		int16_t y = 32 + (((ymax - bufY[i])*127))/(ymax - ymin);							//scales y from 32 to 159 (need space for the title at the top, so start at 32)
		ST7735_DrawPixel(x, y, ST7735_BLUE);
	}
};
