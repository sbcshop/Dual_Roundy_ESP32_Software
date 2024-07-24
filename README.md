# Dual_Roundy_ESP32_Software

# Dual_Roundy_Pico_Software

<img src= "" />

Dual Roundy ESP32 has two 1.28" Round displays driven by the ESP32 S3 WROOM-1, an array of four WS2812B RGB LEDs, and an inbuilt QMI8658C 6D MEMS IMU, providing the ideal platform for your creative ideas. 
Easy programming using the Type C interface, as well as several dynamic visualization features, make it appropriate for a wide range of unique applications.

This github provides getting started guide for Dual Roundy RP2040.

### Features:



### Specifications:
- **Microcontroller**: RP2040 Dual ARM Cortex-M0+
- **Memory**: 264kB on-chip SRAM, 2MB on-board QSPI flash
- **Supply Voltage**: 5V
- **Operating pin voltage**: 3.3V
- **Display**: 
	- **Display Size**: 1.28” 
	- **Display Type**: IPS TFT Round
	- **Display Resolution**:  240 x 240 pixels
	- **Display colors**: 65K RGB
	- **Display interface**: SPI
	- **Display Driver**: GC9A01A 
- **Battery Support**: 3.7V Lithium Ion 
- **Battery Charge Management**: MCP73831 
- **RGB LED**: WS2812B  
- **6D IMU Sensor**: QMI8658C
- **Operating Temperature Range**: -20°C ~ +70°C 

## Getting Started with Daul Roundy RP2040
### Pinout
<img src= "https://github.com/sbcshop/Dual_Roundy_RP2040_Software/blob/main/images/Dual_Roundy_RP2040_Pinout.jpg" />

| Main Side | Common Side |  Common Side  |
|---|---|---|
| (1) & (5) Programmable Buttons	| (7) 1.28” TFT Display (Bottom) | (14) Charging Status LED |
| (2) RP2040				| (8) Male Header		 | (16) QMI8658C 6D IMU Sensor |
| (3) Boot Button			| (9) Power Status LED		 | (17) TFcard slot 	|
| (4) Female Header			| (10), (13), (15) & (18) WS2812 RGB LED |
| (6) Type C				| (11) Battery Connector	|
| (7) 1.28” TFT Display (Top)		| (12) GPIOs Breakout		|

### Connecting Main and Common board 

Hold Main and common board as shown below and then connect both using provided Male and female header

<img src= "https://github.com/sbcshop/Dual_Roundy_RP2040_Software/blob/main/images/combine_roundy_rp2040.gif"  width="870" height="250" >

### Interfacing Details

When you connect both Main and common board together following pins of RP2040 interfaced with various onboard hardware,

 - **_Dual Display interfacing with ESP32**
	
   | ESP32 | Main Display | Function |
   |---|---|---|
   | GPIO18 | LCD1_CLK | Clock pin of SPI interface for Display|
   | GPIO19 | LCD1_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
   | GPIO17  | LCD1_CS | Chip Select pin of SPI interface|
   | GPIO6 | LCD1_DC| Data/Command (MISO) pin of SPI interface|
   | GPIO7 | LCD1_BL | Backlight of display|
   | GPIO16 | LCD1_RST | Reset of display|
	
   | ESP32 | Common Display | Function |
   |---|---|---|
   | GPIO10 | LCD2_CLK | Clock pin of SPI interface for Display|
   | GPIO11 | LCD2_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
   | GPIO13 | LCD2_CS | Chip Select pin of SPI interface|
   | GPIO14  | LCD2_DC| Data/Command (MISO) pin of SPI interface|
   | GPIO15 | LCD2_BL | Backlight of display|
   | GPIO12 | LCD2_RST | Reset of display|

 - **_SDcard Interface_**
   | ESP32 | SDCard | Function |
   |---|---|---|
   | GPIO2 | CARD_CLK | Clock pin of SPI interface for Display|
   | GPIO3  | CARD_MOSI | MOSI (Master OUT Slave IN) pin of SPI interface|
   | GPIO4 | CARD_MISO  | MISO (Master IN Slave OUT) pin of SPI interface|
   | GPIO5  | CARD_CS  | Chip Select pin of SPI interface|

- **_QMI8658C IMU Interfacing_**
  | ESP32 | IMU | Function |
  |---|---|---|
  |GPIO21 | I2C_SCL | I2C Serial Clock |
  |GPIO20 | I2C_SDA | I2C Data pin |
  
- **_Buttons Interfacing_**
  | ESP32 | Hardware | Function |
  |---|---|---|
  |GPIO22| BT1 | Programmable Button |
  |GPIO9 | BT2 | Programmable Button |
  |GPIO8 | BT3 | Programmable Button |
  
- _**GPIOs Breakout**_
  | ESP32 | Function |
  |---|---|
  | 3V3 | Supply 3.3V  |
  | GP0 | Multipurpose GPIO |
  | GP1 | Multipurpose GPIO |
  | GND | Supply Ground |
  

### Example Codes
   Try reference demo codes to test onboard components, also make sure to save [_**dualdisplay.py**_](https://github.com/sbcshop/Dual_Roundy_RP2040_Software/blob/main/examples/dualdisplay.py) lib file into board
   - [Dual Display Demo](https://github.com/sbcshop/Dual_Roundy_RP2040_Software/blob/main/examples/Demo_DualDisplay.py) : Visualize onboard display working with sample code
   - [6-axis IMU Sensor](https://github.com/sbcshop/Dual_Roundy_RP2040_Software/blob/main/examples/Demo_IMU.py) : To read accelerometer and gyroscope value
   - [Buttons Demo](https://github.com/sbcshop/Dual_Roundy_RP2040_Software/blob/main/examples/Demo_RGB_BTN.py) : Testing onboard user programmable buttons
   - [More...](https://github.com/sbcshop/Dual_Roundy_RP2040_Software/tree/main/examples)

   Using this sample code as a guide, you can modify, build, and share codes!!

## Resources
  * [Main ESP32 Schematic](https://github.com/sbcshop/Dual_Roundy_RP2040_Hardware/blob/main/Design%20Data/SCH%20Dual%20Roundy%20RP2040%20Main.pdf)
  * [Common Board Schematic](https://github.com/sbcshop/Dual_Roundy_RP2040_Hardware/blob/main/Design%20Data/Sch_Dual_Roundy_Common.pdf)
  * [Mechanical Files](https://github.com/sbcshop/Dual_Roundy_RP2040_Hardware/tree/main/Mechanical%20Data)
  * [RP2040 Datasheet](https://github.com/sbcshop/Dual_Squary_RP2040_Software/blob/main/Documents/rp2040-datasheet.pdf)
  * [QMI8658C Datasheet](https://github.com/sbcshop/Dual_Squary_RP2040_Software/blob/main/Documents/QMI8658C.pdf)
  * [MicroPython getting started for RPi Pico/Pico W](https://docs.micropython.org/en/latest/rp2/quickref.html)

## Related Products  
  * [2x2 Display with ESP32 S3 (Round)](https://shop.sb-components.co.uk/products/2x2-quad-display-board?variant=41538301493331)

    ![2x2 Display with ESP32 S3 (Round)](https://shop.sb-components.co.uk/cdn/shop/files/mainroundesp32.png?v=1720527042&width=300)
    
  * [2x2 Display with ESP32 S3 (Square)](https://shop.sb-components.co.uk/products/2x2-quad-display-board?variant=41538301526099)

    ![2x2 Display with ESP32 S3 (Square)](https://shop.sb-components.co.uk/cdn/shop/files/mainsquareesp32.png?v=1720527077&width=300)
    
  * [Touchsy - 3.2" Touch LCD Display Based on Pico W](https://shop.sb-components.co.uk/products/touchsy-3-2-touch-lcd-display-based-on-pico-w?variant=40828148744275)

    ![Touchsy - 3.2" Touch LCD Display Based on Pico W](https://shop.sb-components.co.uk/cdn/shop/files/touchsypicowresitive.jpg?v=1686903806&width=300)
  
  * [Rotary Encoder - LED Array & Touch LCD Powered by Pico W](https://shop.sb-components.co.uk/products/rotary-encoder-led-array-touch-lcd-for-esp32-pico-hat?variant=41002601676883)

    ![Rotary Encoder - LED Array & Touch LCD Powered by Pico W](https://shop.sb-components.co.uk/cdn/shop/files/RotaryEncoder-LEDArray_TouchLCDforESP32PicoHAT_7.png?v=1710413189&width=300)


## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
