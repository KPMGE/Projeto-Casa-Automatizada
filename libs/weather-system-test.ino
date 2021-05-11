#include <WeatherSystem.h>

#define DHT_PIN 2 // pino do sensor DHT (Interrupt)
#define DHT_INTERRUPT 11
#define LED_WEATHER_PIN 9

WeatherSystem weatherSystem(DHT_PIN, DHT_INTERRUPT, LED_WEATHER_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (weatherSystem.getTemperature() > 29 || weatherSystem.getHumidity() > 19) {
    weatherSystem.turnOnLed();
  } else {
    weatherSystem.turnOffLed();
  }

  Serial.print("TemperatureC: ");
  Serial.println(weatherSystem.getTemperature());

  Serial.println("Humidity: ");
  Serial.println(weatherSystem.getHumidity());
}
