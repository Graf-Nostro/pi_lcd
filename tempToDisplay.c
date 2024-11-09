#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <lcd.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7

#define ROWS 2
#define COLUMNS 16

#define BIT 4  //4 or 8 bits
#define UNUSED 0 // unused gpio pins in 4 bit mode

int main( int argc, char **argv ){

  int lcd;
  char buffer[8];

  if(argc != 2) {
    fprintf(stderr, 
            "Parameter needed!\n\nUsage: %s \"Text to display.\"\n",
	    argv[0]);

    return EXIT_FAILURE;
  }

  //copy 7 char from stdin to buffer
  strncpy(buffer, argv[1], sizeof buffer);

  wiringPiSetup();

  lcd = lcdInit(ROWS, COLUMNS, BIT,
		LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 
		UNUSED, UNUSED, UNUSED, UNUSED);

  lcdClear(lcd);

  lcdPosition(lcd, 1, 1); //2 column row 2
  lcdPuts(lcd, buffer); 

  return 0;
}
