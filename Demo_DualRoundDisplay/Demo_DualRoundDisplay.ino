/* Demo Code to Run Test Display of Dual Roundy ESP32*/
/**********************************************************************
   Display interfacing with ESP32
  
   | ESP32 | Display | Function |
   | IO12 | LCD1_CLK | Clock pin of SPI interface for Display|
   | IO11 | LCD1_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
   | IO9  | LCD1_CS | Chip Select pin of SPI interface|
   | IO13 | LCD1_DC| Data/Command (MISO) pin of SPI interface|
   | IO14 | LCD_RST | Reset of display|
   | IO10 | LCD_BL | Backlight of display|
  
   | ESP32 | Display | Function |
   | IO15 | LCD2_CLK | Clock pin of SPI interface for Display|
   | IO6  | LCD2_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
   | IO21 | LCD2_CS | Chip Select pin of SPI interface|
   | IO7  | LCD2_DC| Data/Command (MISO) pin of SPI interface|
   | IO18 | LCD_RST | Reset of display|
   | IO48 | LCD_BL | Backlight of display|
************************************************************************/

//Import required libraries
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"

// Main board Display SPI pins
#define TFT1_CS         9
#define TFT1_MOSI       11
#define TFT1_SCLK       12
#define TFT1_RST        14
#define TFT1_DC         13
#define BACKLIGHT1      10

// Common board Display SPI pins
#define TFT2_CS         21
#define TFT2_MOSI       6
#define TFT2_SCLK       15
#define TFT2_RST        18
#define TFT2_DC         7
#define BACKLIGHT2      48


//create instance for SPI Display 
Adafruit_GC9A01A tft1(TFT1_CS, TFT1_DC, TFT1_MOSI, TFT1_SCLK, TFT1_RST);
Adafruit_GC9A01A tft2(TFT2_CS, TFT2_DC, TFT2_MOSI, TFT2_SCLK, TFT2_RST);

float p = 3.1415926;


void setup() {
  Serial.begin(115200); // Set serial communication baudrate
  tft1.begin(); // Initialize display
  tft2.begin();
  
  pinMode(BACKLIGHT1, OUTPUT); // set backlight pin as OUTPUT
  digitalWrite(BACKLIGHT1, HIGH); // Backlight on
  
  pinMode(BACKLIGHT2, OUTPUT); // set backlight pin as OUTPUT
  digitalWrite(BACKLIGHT2, HIGH); // Backlight on
  
  testdrawcircles(10, GC9A01A_GREEN);
  testroundrects();
  delay(2000);
  
  testtriangles();
  Serial.println("Ready");
}

void loop(void) {
  Serial.println("Loop");
  testdrawtext("1",GC9A01A_YELLOW, 1);
  testdrawtext("2",GC9A01A_YELLOW, 2);
  delay(500);
}

void testdrawtext(char *text, uint16_t color, int choice) {
  if (choice == 1) {
    tft1.setCursor(110, 130);
    tft1.setTextSize(3);
    tft1.setTextColor(color);
    tft1.setTextWrap(true);
    tft1.print(text);
  }
  if (choice == 2){
    tft2.setCursor(110, 130);
    tft2.setTextSize(3);
    tft2.setTextColor(color);
    tft2.setTextWrap(true);
    tft2.print(text);
  }
  
}

void testroundrects() {
  tft1.fillScreen(GC9A01A_BLACK);
  uint16_t color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft1.width()-2;
    int h = tft1.height()-2;
    for(i = 0 ; i <= 32; i+=1) {
      tft1.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  tft2.fillScreen(GC9A01A_BLACK);
  for (int16_t x=0; x < tft2.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft2.height()+radius; y+=radius*2) {
      tft2.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  tft1.fillScreen(GC9A01A_BLACK);
  tft2.fillScreen(GC9A01A_BLACK);
  
  uint16_t color = 0xF800;
  int t;
  
  int w1 = tft1.width()/2;
  int x1 = tft1.height()-1;
  
  int w2 = tft2.width()/2;
  int x2 = tft2.height()-1;
  
  int y1 = 0;
  int y2 = 0;
  
  int z1 = tft1.width();
  int z2 = tft2.width();
  
  for(t = 0 ; t <= 15; t++) {
    tft1.drawTriangle(w1, y1, y1, x1, z1, x1, color);
    tft2.drawTriangle(w2, y2, y2, x2, z2, x2, color);
    x1-=4;
    x2-=4;
    
    y1+=4;
    y2+=4;
    
    z1-=4;
    z2-=4;
    color+=100;
  }
}
