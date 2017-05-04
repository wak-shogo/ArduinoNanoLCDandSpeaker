#include <Wire.h>
#define LCD_ADRS 0x3E
char moji[] ="welcome to yokoso japariPark";
char moji2[] = "wait while";

void writeData(byte t_data)
{
 Wire.beginTransmission(LCD_ADRS);
 Wire.write(0x40);
 Wire.write(t_data);
 Wire.endTransmission();
delay(1);
}
//コマンド書き込み
void writeCommand(byte t_command)
{
   Wire.beginTransmission(LCD_ADRS);
   Wire.write(0x00);
   Wire.write(t_command);
   Wire.endTransmission();
   delay(10);
}
//液晶初期化
void init_LCD() {
  delay(100);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x39);
  delay(20);
  writeCommand(0x14);
  delay(20);
  writeCommand(0x73);
  delay(20);
  writeCommand(0x52);
  delay(20);
  writeCommand(0x6C);
  delay(20);
  writeCommand(0x38);
  delay(20);
  writeCommand(0x01);
  delay(20);
  writeCommand(0x0C);
  delay(20);
}
//LCDへ文字列送信
void LCD_str(char *c) {
  unsigned char i,wk;
  for (i=0 ; ; i++) {
    wk = c[i];
    if  (wk == 0x00) {break;}
    writeData(wk);
  }

}

void setup() {
  Wire.begin();
  init_LCD();
  
  LCD_str(moji);
  
  writeCommand(0x40+0x80); // 2LINE TOP
  LCD_str(moji2);
}
void loop() {
  writeCommand(0b00011000);
  delay(300);
  
} 

