#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "IoT BMS RF Model"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// --- Network & Cloud Credentials ---
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// --- Hardware Pin Configurations ---
#define DHTPIN         4   // DHT11 Temperature Sensor Pin
#define DHTTYPE        DHT11
#define MQ135_PIN      34  // Analog pin for Smoke/Gas Sensor
#define VOLTAGE_PIN    35  // Analog pin for Battery Voltage monitoring
#define RELAY_PIN      2   // Controls the Spray/Safety module
#define LCD_COLUMNS    16
#define LCD_ROWS       2

// --- Initialization ---
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS); 
BlynkTimer timer;

// --- Thresholds for Local Safety Optimization ---
const float CRITICAL_TEMP = 45.0; 
const int CRITICAL_SMOKE  = 1200; 

void readAndStreamBMSData() {
  // 1. Read DHT11 Temperature
  float temperature = dht.readTemperature();
  if (isnan(temperature)) temperature = 0.0;

  // 2. Read MQ135 Smoke Sensor
  int smokeValue = analogRead(MQ135_PIN);

  // 3. Read Battery Voltage
  int vRaw = analogRead(VOLTAGE_PIN);
  float voltage = (vRaw * 3.3 / 4095.0) * 2.0; 

  // 4. Local Optimization / Automated Mitigation Control (Spray/Relay)
  bool hazardDetected = false;
  if (temperature > CRITICAL_TEMP || smokeValue > CRITICAL_SMOKE) {
    hazardDetected = true;
    digitalWrite(RELAY_PIN, LOW); // Activates spray/safety mechanism
  } else {
    digitalWrite(RELAY_PIN, HIGH); 
  }

  // 5. Update Local LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:" + String(voltage, 1) + "V  T:" + String(temperature, 1) + "C");
  lcd.setCursor(0, 1);
  if (hazardDetected) {
    lcd.print("HAZARD! SPRAY ON");
  } else {
    lcd.print("Smoke Level:" + String(smokeValue));
  }

  // 6. Push features to Cloud for Random Forest Regressor input
  Blynk.virtualWrite(V1, voltage);      
  Blynk.virtualWrite(V2, temperature);  
  Blynk.virtualWrite(V3, smokeValue);   
  Blynk.virtualWrite(V4, hazardDetected ? "FAULT" : "HEALTHY");

  // Debug output over Serial
  Serial.printf("V: %.2fV | T: %.1fC | Smoke: %d | Status: %s\n", 
                voltage, temperature, smokeValue, hazardDetected ? "EMERGENCY" : "NORMAL");
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); 

  dht.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("IoT BMS Loading");

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2500L, readAndStreamBMSData);
  lcd.clear();
}

void loop() {
  Blynk.run();
  timer.run();
}