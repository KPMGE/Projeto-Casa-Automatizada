// garage controller for project - We need to detect a car and so,
// open the garage and, at the same time, turns on a led
// Now, using NewPing library

// Author: Kevin Carvalho de Jesus

#include <Servo.h>
#include <NewPing.h>

// constants for servomotor
#define SERVO_PIN 6
int start_position = 0;
int servo_max_angle = 60;
int servo_speed = 15;
// instance of Servo class
Servo servomotor;


// contants for ultrassonic sensor
#define TRIGGER_PIN 9
#define ECHO_PIN 10
int distanceSensor = 200;
float max_reading_dist_cm = 30;
float min_dist_car_cm = 10;
// instance of Ultrassonic class
NewPing sonar(TRIGGER_PIN, ECHO_PIN, max_reading_dist_cm);

// How frequently are we going to send out a ping (in milliseconds)
unsigned int pingSpeed = 50;
// Holds the next ping time.
unsigned long pingTimer;


// contants for led and buttom
#define GARAGE_LED_PIN 13
#define BUTTOM_PIN 3
bool pressedBtn = false;



void setup()
{
	pinMode(GARAGE_LED_PIN, OUTPUT);
	pinMode(BUTTOM_PIN, INPUT_PULLUP);
	digitalWrite(12, HIGH);
	attachInterrupt(digitalPinToInterrupt(BUTTOM_PIN), pressedButton, HIGH);
	servomotor.attach(SERVO_PIN);
	servomotor.write(start_position);
	pingTimer = millis();
	Serial.begin(9600);
}

void loop()
{

	// implementation for garageController
	if (millis() >= pingTimer)
	{
		pingTimer += pingSpeed;
		sonar.ping_timer(echoCheck);
	}
	if (isCarNear() || pressedBtn)
	{
		garageController();
	}

	// we can do anything here, never mind!
}

void openGarageWithServo()
{
	for (int position = 0; position < servo_max_angle; position++)
	{
		servomotor.write(position);
		delay(servo_speed);
	}
}

void closeGarageWithServo()
{
	for (int position = servo_max_angle; position >= 0; position--)
	{
		servomotor.write(position);
		delay(servo_speed);
	}
}

void turnOnLedGarage()
{
	digitalWrite(GARAGE_LED_PIN, HIGH);
}

void turnOffLedGarage()
{
	digitalWrite(GARAGE_LED_PIN, LOW);
}

void echoCheck()
{
	if (sonar.check_timer())
	{
		distanceSensor = sonar.ping_result / US_ROUNDTRIP_CM;
		Serial.print("Ping: ");
		Serial.print(distanceSensor);
		Serial.println("cm");
	}
}

bool isCarNear()
{
	return distanceSensor < min_dist_car_cm;
}

void garageController()
{
	turnOnLedGarage();
	openGarageWithServo();

	delay(4000);

	closeGarageWithServo();
	turnOffLedGarage();

	distanceSensor = 200;
	pressedBtn = false;
}

void pressedButton()
{
	pressedBtn = true;
}
