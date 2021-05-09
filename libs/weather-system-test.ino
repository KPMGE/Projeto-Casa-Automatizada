#include <WeatherSystem.h>

#define DHT_PIN 2 // pino do sensor DHT (Interrupt)
#define DHT_INTERRUPT 11

WeatherSystem weatherSystem(DHT_PIN, DHT_INTERRUPT);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("TemperatureC: ");
  Serial.println(weatherSystem.getTemperature());

  Serial.println("Humidity: ");
  Serial.println(weatherSystem.getHumidity());
}
