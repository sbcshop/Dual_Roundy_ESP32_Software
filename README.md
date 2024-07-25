# Dual_Roundy_ESP32_Software

<img src= "" />

Dual Roundy ESP32 has two 1.28" Round displays driven by the ESP32 S3 WROOM-1, an array of four WS2812B RGB LEDs, and an inbuilt QMI8658C 6D MEMS IMU, providing the ideal platform for your creative ideas. 
Easy programming using the Type C interface, as well as several dynamic visualization features, make it appropriate for a wide range of unique applications.

This github provides getting started guide for Dual Roundy ESP32.

### Features:
- Powered by ESP32 S3 Wroom-1 microcontroller module
- Dual 1.28” Round display arrangement for creative visual interactions
- Board features an array of four WS2812B RGB Led with true 16M color support
- Onboard QMI8658C 6D MEMS inertial measurement unit, incorporates a 3-axis gyroscope and a 3- axis accelerometer
- Power and Charging LED for status indication
- Battery hookup and charging facilities for portability
- Onboard microSD card support for data logging purposes
- Multipurpose GPIOs breakout for additional peripheral interfacing
- Boot and Reset Button for programming
- Type C interface for power and programming purpose
- Two User Programmable Buttons to add additional controls to project 
- Supports multiple programming language like Arduino, MicroPython, and CircuitPython  


### Specifications:
- **Microcontroller**: ESP32 S3 WROOM-1, Xtensa® dual-core 32-bit LX7 microprocessor
- **Connectivity**: 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth® 5 (LE) 
- **Memory**: Flash up to 16 MB, PSRAM up to 8 MB
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

## Getting Started with Daul Roundy ESP32
### Pinout
<img src= "https://github.com/sbcshop/Dual_Roundy_ESP32_Software/blob/main/images/Dual_Roundy_ESP32_Pinout.jpg" />

| Main Side | Common Side |  
|---|---|
| (1) Female Header 			| (8) Male Header			 |  
| (2) Reset Button			| (9) Power Status LED			 | 
| (3) ESP32 S3 Wroom 1			| (10), (13), (15) & (18) WS2812 RGB LED |		
| (4) Programmable Buttons		| (11) Battery Connector		 |
| (5) Type C				| (12) GPIOs Breakout			 |
| (6) Boot Button			| (14) Charging Status LED		 |
| (7) 1.28” TFT Display			| (16) QMI8658C 6D IMU Sensor 		 |
|					| (17) TFcard slot 			 |

### Connecting Main and Common board 

Hold Main and common board as shown below and then connect both using provided Male and female header

<img src= ""  width="" height="" >

### Interfacing Details

When you connect both Main and common board together following pins of ESP32 S3 interface with various onboard hardware,

### Interfacing Details

 - **_Display interfacing with ESP32_**
	
   | ESP32 | Display | Function |
   |---|---|---|
   | IO12 | LCD1_CLK | Clock pin of SPI interface for Display|
   | IO11 | LCD1_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
   | IO9  | LCD1_CS | Chip Select pin of SPI interface|
   | IO13 | LCD1_DC| Data/Command (MISO) pin of SPI interface|
   | IO45 | LCD_BL | Backlight of display|
	
   | ESP32 | Display | Function |
   |---|---|---|
   | IO15 | LCD2_CLK | Clock pin of SPI interface for Display|
   | IO6  | LCD2_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
   | IO21 | LCD2_CS | Chip Select pin of SPI interface|
   | IO7  | LCD2_DC| Data/Command (MISO) pin of SPI interface|
   | IO45 | LCD_BL | Backlight of display|


 - **__SDcard Interface__**
   | ESP32 | SDCard | Function |
   |---|---|---|
   | IO42 | CARD_CLK | Clock pin of SPI interface for Display|
   | IO2  | CARD_MOSI | MOSI (Master OUT Slave IN) pin of SPI interface|
   | IO41 | CARD_MISO  | MISO (Master IN Slave OUT) pin of SPI interface|
   | IO1  | CARD_CS  | Chip Select pin of SPI interface|
   
<!--   
 - **_Type C Native ESP USB Interface_**
   | ESP32 | Native USB | Description | 
   |---|---|---|
   | IO19 | D- | USB Communication pin |
   | IO20 | D+ | USB Communication pin |
-->	 
  
- **_BME280 & DS3231 RTC I2C Interfacing_**
  | ESP32 | Hardware | Hardware | Function |
  |---|---|---|---|
  |IO39 | BME280_SCL | RTC_SCL | I2C Serial Clock |
  |IO38 | BME280_SDA  | RTC_SDA | I2C Data pin |
  
- **_Buttons & Buzzer Interfacing_**
  | ESP32 | Hardware | Function |
  |---|---|---|
  |IO0 | BOOT |Boot button |
  |IO4 | BT1 | Programmable Button |
  |IO5 | BT2 | Programmable Button |
  |IO40 | Buzzer | Buzzer control pin |
	
- **_GPIOs Breakout_**
  
  | ESP32 | Type* | Multi-Function (_**Bold-Italic**_ default Function) |
  |---|---|---|
  |3V3  | P     | Positive Supply, 3.3V |
  |IO3  | I/O/T | RTC_GPIO3, _**GPIO3**_, TOUCH3, ADC1_CH2  |
  |IO46 | I/O/T | _**GPIO46**_ |  
  |GND  | P     | Supply Ground |
  
  *I-INPUT, O-OUTPUT, P-POWER & T-HIGH IMPEDENCE

### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - On Dual Roundy for ESP32 we have Native USB for programming purpose, so you will have to press BOOT button once and then connect Type C. Next time no need, but if facing any issue with COM Port detection the repeat BOOT button step.

     <img src="https://github.com/sbcshop/Dual_Roundy_ESP32_Software/blob/main/images/dual_roundy_ESP32_bootBTN.gif" width="338" height="314">
     
   - When using USB native you will get COM PORT as shown in below image, and while uploading you can enable CDC Mode to visualize data on serial com port.
     
     <img src="https://github.com/sbcshop/2x2_Display_ESP32_Software/blob/main/images/Native_USB_device_com_port.jpg" width="410" height="93">
     
     <img src="https://github.com/sbcshop/2x2_Display_ESP32_Software/blob/main/images/Native_USB_Arduino_com.jpg" width="" height="">
     

### 2. Installing Libraries
   - Download [library zip file]() provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### 3. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes]() in github which you can download and try.
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on ESP32 of Roundy.
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/upload_process.gif">

### Example Codes
   Try reference demo codes to test onboard components and make sure to [setup libraries]() before to avoid compilation error of any demo codes,
   - [Dual Display Demo]() : Visualize onboard display working with sample code
   - [6-axis IMU Sensor]() : To read accelerometer and gyroscope value
   - [Buttons Demo]() : Testing onboard user programmable buttons
   - [More...]()

   Using this sample code as a guide, you can modify, build, and share codes!!

## Resources
  * [Main ESP32 Schematic](https://github.com/sbcshop/Dual_Roundy_ESP32_Hardware/blob/main/Design%20Data/SCH%20Dual%20Roundy%20esp32%20Main.pdf)
  * [Common Board Schematic](https://github.com/sbcshop/Dual_Roundy_ESP32_Hardware/blob/main/Design%20Data/Sch_Dual_Roundy_Common.pdf)
  * [Mechanical Files](https://github.com/sbcshop/Dual_Roundy_ESP32_Hardware/tree/main/Mechanical%20Data)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/Dual_Roundy_ESP32_Software/blob/main/Documents/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
  * [QMI8658C Datasheet](https://github.com/sbcshop/Dual_Roundy_ESP32_Software/blob/main/Documents/QMI8658C.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)

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
