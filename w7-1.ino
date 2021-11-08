#include <Wire.h>
#include "SSD1306Wire.h"
SSD1306Wire  display(0x3c, 21, 22);

void setup() {
    Serial.begin(115200);
    pinMode(14,INPUT);
    // Initialising the UI will init the display too.
    display.init();

    display.flipScreenVertically(); //畫面上下顛倒顯示

    display.clear(); //清空畫面 
   display.display(); //顯示畫面
}

void loop() {
   display.clear(); //清空畫面 
    display.setFont(ArialMT_Plain_16);   //設定字型與大小
    display.drawString(0, 0, "Value");  //(x座標,y座標,"字串")
    display.setFont(ArialMT_Plain_24);   //設定字型與大小
    display.drawString(0,16, String(analogRead(14)));  //(x座標,y座標,"字串")
    Serial.println(analogRead(14));
    
   display.display(); //顯示畫面
}
