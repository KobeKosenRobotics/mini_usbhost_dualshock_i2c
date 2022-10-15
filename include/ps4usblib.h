#ifndef PS3USBLIB_H
#define PS3USBLIB_H


#include <PS4USB.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
/* You can create the instance of the class in two ways */
PS4USB PS3(&Usb); // This will just create the instance
//PS3USB PS3(&Usb,0x00,0x15,0x83,0x3D,0x0A,0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch




int datazz[6];

#define LX datazz[3]
#define LY datazz[1]
#define RX datazz[2]
#define RY datazz[0]
#define AR2 datazz[4]
#define AL2 datazz[5]
//C_はボタンが押された瞬間一度だけ１になる
#define C_SANKAKU PS3.getButtonClick(TRIANGLE)
#define C_MARU PS3.getButtonClick(CIRCLE)
#define C_BATU PS3.getButtonClick(CROSS)
#define C_SIKAKU PS3.getButtonClick(SQUARE)
#define C_UE PS3.getButtonClick(UP)
#define C_MIGI PS3.getButtonClick(RIGHT)
#define C_SITA PS3.getButtonClick(DOWN)
#define C_HIDARI PS3.getButtonClick(LEFT)
#define C_L1 PS3.getButtonClick(L1)
#define C_R1 PS3.getButtonClick(R1)
#define C_SELECT PS3.getButtonClick(SELECT)
#define C_START PS3.getButtonClick(START)
#define C_L3 PS3.getButtonClick(L3)
#define C_R3 PS3.getButtonClick(R3)
//P_はボタンが押されている間１になる
#define P_SANKAKU PS3.getButtonPress(TRIANGLE)
#define P_MARU PS3.getButtonPress(CIRCLE)
#define P_BATU PS3.getButtonPress(CROSS)
#define P_SIKAKU PS3.getButtonPress(SQUARE)
#define P_UE PS3.getButtonPress(UP)
#define P_MIGI PS3.getButtonPress(RIGHT)
#define P_SITA PS3.getButtonPress(DOWN)
#define P_HIDARI PS3.getButtonPress(LEFT)
#define P_L1 PS3.getButtonPress(L1)
#define P_R1 PS3.getButtonPress(R1)
#define P_SELECT PS3.getButtonPress(SELECT)
#define P_START PS3.getButtonPress(START)
#define P_L3 PS3.getButtonPress(L3)
#define P_R3 PS3.getButtonPress(R3)
#define PS_CONNECTED PS3.connected()


void bt_set(){
  Serial.begin(250000);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started"));
}

void bt_setnotSerial(){
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started"));
}


void bt_jusin(){
     Usb.Task();
   if (PS3.connected()==1){
      datazz[0]=PS3.getAnalogHat(RightHatY);
      datazz[1]=PS3.getAnalogHat(LeftHatY);
      datazz[2]=PS3.getAnalogHat(RightHatX);
      datazz[3]=PS3.getAnalogHat(LeftHatX);
      datazz[4]=PS3.getAnalogButton(R2);
      datazz[5]=PS3.getAnalogButton(L2);
      //if (PS3.getButtonClick(PS));
   }
   else{
    datazz[0]=127;
    datazz[1]=127;
    datazz[2]=127;
    datazz[3]=127;
    datazz[4]=0;
    datazz[5]=0;
   }
}

void bt_print(){
     for(int i=0;i<6;i++){
      Serial.print(datazz[i]);
      Serial.print("\r ");
     }
}

void bt_println(){
  bt_print();
  Serial.println();
}

#endif
