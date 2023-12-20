kirkusreview.com/about/careers
reedsy.com/discovery
booklistonline.com
onlinebookclub.org
/**********************************************************************************
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *
 *  Download the libraries 
 *  Blynk Library (1.1.0):  https://github.com/blynkkk/blynk-library
 **********************************************************************************/

/* Fill-in your Template ID (only if using Blynk.Cloud) */
#define BLYNK_TEMPLATE_ID "TMPL2xBQQNHfq"
#define BLYNK_TEMPLATE_NAME "Smart Home"
#define BLYNK_AUTH_TOKEN "Your AUTH token provided by Blynk"

//WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MTN_4G_457AA7";
char pass[] = "mifiiPass";
char auth[] = BLYNK_AUTH_TOKEN;
//"C60B97E7";


#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 14, 27, 26, 25);
#define BLYNK_PRINT Serial
#include "EmonLib.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Preferences.h>

Preferences pref;
EnergyMonitor emon;
BlynkTimer timer;
 

float kWh = 0;
unsigned long lastmillis = millis();
 
void myTimerEvent()
{
  emon.calcVI(20, 2000);
  kWh = kWh + emon.apparentPower * (millis() - lastmillis) / 3600000000.0;
  yield();
  Serial.print("Vrms: ");
  Serial.print(emon.Vrms, 2);
  Serial.print("V");
 
  Serial.print("\tIrms: ");
  Serial.print(emon.Irms, 2);
  Serial.print("A");
 
  Serial.print("\tApparent Power: ");
  Serial.print(emon.apparentPower, 2);
  Serial.print("W");
 
  Serial.print("\tkWh: ");
  Serial.print(kWh, 3);
  Serial.println("kWh");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vrms:");
  lcd.print(emon.Vrms, 2);
  lcd.print("V");
  lcd.setCursor(0, 1);
  lcd.print("Irms:");
  lcd.print(emon.Irms, 2);
  lcd.print("A");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Power:");
  lcd.print(emon.apparentPower, 3);
  lcd.print("W");
  lcd.setCursor(0, 1);
  lcd.print("kWh:");
  lcd.print(kWh, 3);
  lcd.print("W");
  delay(2000);
 
  lastmillis = millis();
 
  Blynk.virtualWrite(V5, emon.Vrms);
  Blynk.virtualWrite(V6, emon.Irms);
  Blynk.virtualWrite(V7, emon.apparentPower);
  Blynk.virtualWrite(V8, kWh);
}
 
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  lcd.begin(16, 2);
 
  emon.voltage(35, 83.3, 1.7); // Voltage: input pin, calibration = 83.3, phase_shift
  emon.current(34, 0.50); // Current: input pin, calibration = 0.50.
 
  timer.setInterval(1000L, myTimerEvent);
  lcd.setCursor(3, 0);
  lcd.print("IoT Energy");
  lcd.setCursor(5, 1);
  lcd.print("Meter");
  delay(3000);
  lcd.clear();
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
