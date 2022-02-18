/*--------------------------------------------------------------------------------------------*/
/*                                 Copywrite John W. Mulholland                               */
/*                                     and Eric Tarkelson                                     */
/*                                        FIRMWARE V2.4                                       */
/*                                          1/14/2022                                         */
/*--------------------------------------------------------------------------------------------*/
#include "SensorEvolve.cpp"

//Main Settings for board
void setup() {
    Serial.begin(9600);
    Serial.println(FIRMWARE_Version);
    WiFi.setPins(8,7,4,2);
    WiFi.begin(ssid, pass);
    Wire.begin();
    delay(2000);
    for (uint8_t t=0; t<8; t++) {
      tcaselect(t);
      Serial.print("TCA Port #"); Serial.println(t);
      for (uint8_t addr = 0; addr<=127; addr++) {
        if (addr == TCAADDR) continue;
        Wire.beginTransmission(addr);
        if (!Wire.endTransmission()) {
          Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
          am2315s1.begin();
          am2315s2.begin();
          am2315s3.begin();
          am2315s3.begin();
          am2315s4.begin();
          am2315s5.begin();
        }
      }
    }
    Serial.println("\ndone");
    pinMode(13, OUTPUT);
    pinMode(8, OUTPUT);
    delayRunning = true;
    LogsDelay.start(5000);
}

//Main Loop
void loop(void) {
  ServerUpload();
}
