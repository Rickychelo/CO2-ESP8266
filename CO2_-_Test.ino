#include <Wire.h>
#include "SparkFun_SCD4x_Arduino_Library.h"

// Pinout for ESP8266
#define SDA_PIN 14 //D5 - GPIO14
#define SCL_PIN 12 //D6 - GPIO12

SCD4x sensor;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!sensor.begin()) {
    Serial.println("Error al iniciar el sensor!");
    while (1);
  }

  Serial.println("Sensor SCD41 iniciado correctamente!");
}

void loop() {
    if (sensor.readMeasurement()) {
      float co2 = sensor.getCO2();
      float temp = sensor.getTemperature();
      float humidity = sensor.getHumidity();

      Serial.print("CO2: ");
      Serial.print(co2);
      Serial.print(" ppm, Temperatura: ");
      Serial.print(temp);
      Serial.print(" °C, Humedad: ");
      Serial.print(humidity);
      Serial.println(" %");

      
    } else {
      Serial.println("Error al leer el sensor!");
    }
  
  delay(5000); // Espera 5 segundos antes de la próxima lectura
}
