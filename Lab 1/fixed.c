// filename ******** fixed.c ************** 
// Implementation for fixed.h functions 
// Abraham Gonzalez, Madhumitha Venkataraman
// 8/25/2016
#include "fixed.h"

/****************ST7735_sDecOut3****************/ 
void ST7735_sDecOut3(int32_t n) {
	if (n < -9999 || n > 9999) {
		fputc(' ', 0); 
		fputc('*', 0); 
		fputc('.', 0); 
		fputc('*', 0); 
		fputc('*', 0);
		fputc('*', 0); 
	}
	else {
		if (n < 0) {
			n = n * -1; 
			fputc('-', 0); 
		}
		else { 
			fputc(' ', 0);
    }			
		int divisor = 1000; 
		char outputChar; 
		for (unsigned int i = 0; i < 4; i++) {
			if (i == 1) {
				fputc('.', 0); 
			}
			outputChar = n/divisor; 
			outputChar += 0x30;
			fputc(outputChar, 0); 
			n = n % divisor; 
			divisor = divisor / 10; 
		}
	}
}
/**************ST7735_uBinOut8****************/
void ST7735_uBinOut8(uint32_t n){
	double newN = n;
	newN /= 256;
	newN *= 100;
	int upToZero = 1;
	
	if( n >= 256000 ){
		fputc('*', 0); 
		fputc('*', 0); 
		fputc('*', 0); 
		fputc('.', 0); 
		fputc('*', 0);
		fputc('*', 0);
		return;
	}
	
	int divisor = 10000;
	char outputChar;
	for (unsigned int i = 0; i < 5; i++){
		if ( i == 3 ){
			fputc( '.' , 0 );
		}
		outputChar = newN/divisor; 
		if( (outputChar == 0) && (upToZero == 1) && (i < 2)){
			fputc( ' ' , 0 );
			newN = (int)newN % divisor; 
			divisor = divisor / 10; 
		}
		else {
			upToZero = 0;
			outputChar += 0x30;
			fputc(outputChar, 0); 
			newN = (int)newN % divisor; 
			divisor = divisor / 10; 
		}
	}
}

/**************ST7735_XYplotInit****************/
void ST7735_XYplotInit(char *title, int32_t minX, int32_t maxX, int32_t minY, int32_t maxY);

/**************ST7735_XYplot****************/
void ST7735_XYplot(uint32_t num, int32_t bufX[], int32_t bufY[]);



