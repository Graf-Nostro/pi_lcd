#include <stdio.h>
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

int main( int argc, char **argv ){

  int lcd;
  char *out;

  if( argc != 2 ) {
    printf( "Parameter needed!\n\nUsage: %s \"Text to display.\"\n", argv[0] );

    return -1;
  }

  wiringPiSetup();

  lcd = lcdInit ( 2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0 );

  lcdPuts( lcd, argv[1] );

  return 0;
}
