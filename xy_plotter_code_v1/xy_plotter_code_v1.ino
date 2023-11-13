#include <Arduino.h>
#include <SCMD.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

SCMD myMotorDriver; 
Servo myServo;

char ssid[] = "Penplotter";
char pass[] = "Password";
char auth[] = "Dey42G7_jqfytbSaX3GC5SmGzeP28UN2";

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
#define PIN_SERVO 13

long stateChangeCount =  0;
long stateChangeCount_33 =  0;

int x_ryt = 17;
int x_left = 21;
int y_top = 23;
int y_bottom = 16;

void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(x_ryt, INPUT_PULLUP);
  pinMode(x_left, INPUT_PULLUP);
  pinMode(y_top, INPUT_PULLUP);
  pinMode(y_bottom, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(32), countStateChange, CHANGE);
  
  attachInterrupt(digitalPinToInterrupt(33), countStateChange, CHANGE);

  myServo.attach(PIN_SERVO);

  // Configure the Motor Driver's Settings
  myMotorDriver.settings.commInterface = I2C_MODE;  // setting communication protocol
  myMotorDriver.settings.I2CAddress = 0x5D;  // Set the I2C address
  myMotorDriver.settings.chipSelectPin = 10; // Set the chip select pin

  WiFi.begin(ssid, pass);   // Connect to Wi-Fi
  
  while (WiFi.status() != WL_CONNECTED)  // checking if wifi is connected 
  {
    delay(500);
    Serial.println("Connecting to WiFi...");
    Serial.println("Auth: " + String(auth) + ", SSID: " + String(ssid) + ", Password: " + String(pass));
  }
  
  Serial.println("Connected to WiFi");

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);  // connecting to Blynk
  Serial.println("Connected to Blynk");
  
  // Initialize the driver and wait for idle
  while (myMotorDriver.begin() != 0xA9)
  {
    Serial.println("ID mismatch, trying again");
    //Blynk.virtualWrite(V7, "ID mismatch, trying again");   // Motor driver connection status
    delay(500);
  }
  
  Serial.println("ID matches 0xA9");
  //Blynk.virtualWrite(V7, "ID matches 0xA9");  // Motor driver connection status

  // Wait for the driver to finish looking for peripherals
  while (!myMotorDriver.ready())
  {
    Serial.println("Waiting for enumeration...");  // output on serial monitor
    //Blynk.virtualWrite(V7, "Waiting for enumeration...");      // Motor driver connection status output on Blynk
    delay(100);
  }
  
  //set the resolution to 12 bits (0-4096)
  //analogReadResolution(12);
  myMotorDriver.enable();
  Serial.println("Motor enabled");
}

void loop() {
  
  Blynk.run();

}

BLYNK_WRITE(V6) {

  int ButtonState = param.asInt();
  Serial.println(ButtonState);

  if (ButtonState == 1) {
    Serial.println("lifting");
    pen_lift();
  }

  if (ButtonState == 0) {
    Serial.println("lifting");
    pen_down();
  }
}

BLYNK_WRITE(V4) {
  int ButtonState = param.asInt();

  if (ButtonState == 1) {
    Serial.println("motor started");

    home();
    delay(100);
    
    stateChangeCount = 0;
    while(stateChangeCount < 545)
    {
      Serial.println("moving 1");
      Serial.println(stateChangeCount);
      moveBaseLeftToRight(200);
      
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;
    while(stateChangeCount < 545)
    {
      Serial.println("moving 2");
      Serial.println(stateChangeCount);
      moveBottomToTopRightWall(200);
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;    
    while(stateChangeCount < 545)
    {
      Serial.println("moving 3");
      Serial.println(stateChangeCount);
      moveTopBaseRightToLeft(200);
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;
    while(stateChangeCount < 364)
    {
      Serial.println("moving 4");
      Serial.println(stateChangeCount);
      moveDiagonalTopLeftToMid(250);
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;
    while(stateChangeCount < 364)
    {
      Serial.println("moving 5");
      Serial.println(stateChangeCount);
      moveDiagonalTopMidToRight(250);
    }
    stopMotors();
    delay(500);
    
    stateChangeCount = 0;
    while(stateChangeCount < 782)
    {
      Serial.println("moving 6");
      Serial.println(stateChangeCount);
      moveDiagonalRightWallToLeftWallBottom(250);
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;
    while(stateChangeCount < 545)
    {
      Serial.println("moving 7");
      Serial.println(stateChangeCount);
      moveLeftWall(200);
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;
    while(stateChangeCount < 782)
    {
      Serial.println("moving 8");
      Serial.println(stateChangeCount);
      moveDiagonalLeftWallTopToRightWallBottom(250);
    }
    stopMotors();
    delay(500);

    stateChangeCount = 0;
    while(stateChangeCount < 545)
   {
      Serial.println("moving 9");
      Serial.println(stateChangeCount);
      moveTopBaseRightToLeft(200);
    }
    stopMotors();
    delay(500);
    
    
    stopMotors();  // stopping motors
    delay(1000);

    
  }
//  else{
//    stateChangeCount = 0;
//    }
}
void emergency(){

}
