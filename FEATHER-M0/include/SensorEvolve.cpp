#include "SensorEvolve.h"

void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}
void AllSensors() {
  tcaselect(0);
  am2315s1.readTemperatureAndHumidity(&temp_avgerage1, &humi_avgerage1);
  temp1_db = temp_avgerage1;
  humi1_db = humi_avgerage1;
  tcaselect(1);
  am2315s2.readTemperatureAndHumidity(&temp_avgerage2, &humi_avgerage2);
  temp2_db = temp_avgerage2;
  humi2_db = humi_avgerage2;
  tcaselect(2);
  am2315s3.readTemperatureAndHumidity(&temp_avgerage3, &humi_avgerage3);
  temp3_db = temp_avgerage3;
  humi3_db = humi_avgerage3;
  tcaselect(3);
  am2315s4.readTemperatureAndHumidity(&temp_avgerage4, &humi_avgerage4);
  temp4_db = temp_avgerage4;
  humi4_db = humi_avgerage4;
  tcaselect(4);
  am2315s5.readTemperatureAndHumidity(&temp_avgerage5, &humi_avgerage5);
  tempRoom_db = temp_avgerage5;
  humiRoom_db = humi_avgerage5;
  Serial.println("Trying to connect to server");
  String INSERT_SQL1 = String("INSERT INTO ") + default_database + "." + default_table + "(temp1_db, humi1_db, temp2_db, humi2_db, temp3_db, humi3_db, temp4_db, humi4_db, tempRoom_db, humiRoom_db) VALUES ('"+temp1_db+"','"+humi1_db+"','"+temp2_db+"','"+humi2_db+"','"+temp3_db+"','"+humi3_db+"','"+temp4_db+"','"+humi4_db+"','"+tempRoom_db+"','"+humiRoom_db+"')";
  conn.connect(server_addr, server_port, user, password);
  MySQL_Query query_mem = MySQL_Query(&conn);
  if (conn.connected()) {
    MYSQL_DISPLAY(INSERT_SQL1);
    if ( !query_mem.execute(INSERT_SQL1.c_str()) ) {
      MYSQL_DISPLAY("Insert error");
      conn.close();
    }
    else {
      MYSQL_DISPLAY("Data Inserted.");
    }
  }
  else {
    Watchdog.enable(4000);
    Serial.println("Could not connect to server");
    Serial.println("or");
    MYSQL_DISPLAY("Disconnected from Server. Can't insert.");
    Serial.println("Reboot in 4");
    delay(1000);
    Serial.println("Reboot in 3");
    delay(1000);
    Serial.println("Reboot in 2");
    delay(1000);
    Serial.println("Reboot in 1");
    delay(1100);
    Serial.print("You Should Not See Me!");
    }
}
void ServerUpload() {
      if (LogsDelay.justFinished()) {
          LogsDelay.repeat();
          THW_Delay = !THW_Delay;
          if (THW_Delay) {
            AllSensors();
          }
        }
      }
