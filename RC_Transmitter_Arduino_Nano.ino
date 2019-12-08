#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
#include <Wire.h>
//RC drone transmitter
#define tGL1 7
#define tGL2 6


const int MPU = 0x68; // MPU6050 I2C address
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY;
float angleX, angleY;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY;
float elapsedTime, currentTime, previousTime;
int c = 0;

RF24 radio(9,10);
const byte address[6]="00001";

struct Data_Package {
  byte yaw;
  byte roll;
  byte pitch;
  byte throttle;
  byte tSwitch1;
  byte tSwitch2;

};

Data_Package data;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 // initialize_MPU6050();

  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);

  pinMode(tGL1, INPUT_PULLUP);
  pinMode(tGL2, INPUT_PULLUP);


   data.yaw = 127; // Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
   data.roll = 127;
   data.pitch = 127;
   data.throttle = 0;
  data.tSwitch1 = 0;
  data.tSwitch2 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  data.yaw = map(analogRead(A2), 0, 1023, 0, 255); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.roll = map(analogRead(A3), 0, 1023, 0, 255);
  data.pitch = map(analogRead(A0), 0, 1023, 0, 255);
  data.throttle = map(analogRead(A7), 0, 1023, 0, 255);

  
  data.tSwitch1 = digitalRead(tGL1); 
  data.tSwitch2 = digitalRead(tGL2);  
  
  radio.write(&data, sizeof(Data_Package));
}


