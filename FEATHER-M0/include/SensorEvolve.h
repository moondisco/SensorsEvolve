
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SleepyDog.h>
#include <Adafruit_I2CDevice.h>
#include <WiFi101.h>
#include <MySQL_Generic_WiFi.h>
#include <millisDelay.h>
#include <Adafruit_AM2315.h>
#include <Adafruit_Sensor.h>
#include "wifilogin.h"
#ifndef SENSOREVOLVE_H
#define SENSOREVOLVE_H

//FIRMWARE
const char *FIRMWARE_Version = "Firmware v2.4";


//Multiplexer
#define TCAADDR 0x70
Adafruit_AM2315 am2315s1;
Adafruit_AM2315 am2315s2;
Adafruit_AM2315 am2315s3;
Adafruit_AM2315 am2315s4;
Adafruit_AM2315 am2315s5;

// IPAddress server(10,10,10,10);  //Pi's IP address
// WiFiUDP ntpUDP;
byte mac2[] = { 0xF8,0xF0,0x5,63,0xB6,0xBB };  // change if necessary
byte ip[] = { 10,10,10,10 };
byte gateway[] = { 10, 10, 10, 10 }; // internet access via router
byte subnet[] = { 255, 255, 255, 0 }; //subnet mask
WiFiClient client2;

//wifi wifilogin
//please enter your sensitive data in the Secret libary folder wifilogin.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int led =  LED_BUILTIN;
int status = WL_IDLE_STATUS;     // the WiFi radio's status
bool WiFi_Delay = false;

//MySQL Query/Insert
// IPAddress server_addr(10,10,10,10);
IPAddress server_addr(10,42,0,1);
uint16_t server_port = 3306;
char default_database[] = "grafanadb";
char default_table[]    = "feather_m0_sensors";
MySQL_Connection conn((Client *)&client2);
MySQL_Query *query_mem;
float temp1_db;
float humi1_db;
float temp2_db;
float humi2_db;
float temp3_db;
float humi3_db;
float temp4_db;
float humi4_db;
float tempRoom_db;
float humiRoom_db;

//Delay,SD and RTC
millisDelay LogsDelay;
unsigned long delayStart = 0;
bool delayRunning = false;
bool THW_Delay = false;

//Arrays for Data Memsurements
const unsigned long eventInterval = 2500;
unsigned long previousTime = 0;

float room_avgerage;
float temp_avgerage1;;
float humi_avgerage1;
float temp_avgerage2;
float humi_avgerage2;
float temp_avgerage3;
float humi_avgerage3;
float temp_avgerage4;
float humi_avgerage4;
float temp_avgerage5;
float humi_avgerage5;

int chk;
float humRoom;  //Stores humidity value
float tempRoom; //Stores temperature value
#endif
