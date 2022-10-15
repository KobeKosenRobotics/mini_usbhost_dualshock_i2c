/**
* @file main.cpp
* @brief miniusb host sheild for naviton
* @author Shunya Hara
* @date 2022.10.15
* @details 
*/


/****************************Config*******************************/

//一つだけコメントアウトをはずして有効化する
//#include"ps3usblib.h"//PS3 USB
//#include"ps3btlib.h"//PS3 Bluetooth
//#include"ps4usblib.h"//PS4 USB
#include"ps4btlib.h"//PS4 Bluetooth

//このマイコンのI2Cスレーブアドレス
const int device_address=0x73;

/****************************************************************/

#include<Wire.h>
byte tdata[10];
void sousin(){
  Wire.write(tdata,8);
}

void setup() {
  delay(500);
  // put your setup code here, to run once:
  Wire.begin(device_address);
  //Wire.setClock(400000UL);
  Wire.onRequest(sousin);
  Serial.begin(115200);
  bt_setnotSerial();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  bt_jusin();
  //bt_println();
  tdata[0]=LY;
  tdata[1]=LX;
  tdata[2]=RY;
  tdata[3]=RX;
  tdata[4]=AL2;
  tdata[5]=AR2;

  bitWrite(tdata[6],0,P_MARU);
  bitWrite(tdata[6],1,P_SANKAKU);
  bitWrite(tdata[6],2,P_SIKAKU);
  bitWrite(tdata[6],3,P_BATU);
  bitWrite(tdata[6],4,P_UE);
  bitWrite(tdata[6],5,P_MIGI);
  bitWrite(tdata[6],6,P_SITA);
  bitWrite(tdata[6],7,P_HIDARI);

  bitWrite(tdata[7],0,P_L1);
  bitWrite(tdata[7],1,P_R1);
  bitWrite(tdata[7],2,PS3.getButtonPress(L3));
  bitWrite(tdata[7],3,PS3.getButtonPress(R3));
  bitWrite(tdata[7],4,P_START);
  bitWrite(tdata[7],5,P_SELECT);
  bitWrite(tdata[7],6,PS3.getButtonPress(PS));
  bitWrite(tdata[7],7,PS_CONNECTED);

  //delay(5);
  for(int i=0;i<8;i++){
        Serial.print(tdata[i]);
        Serial.print(",");
    }
  Serial.println();

}
