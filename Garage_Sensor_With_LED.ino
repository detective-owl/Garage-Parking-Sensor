#include <Wire.h>
#include <LiquidCrystal_I2C.h> //LCD Library
// Defines the total number of threshold LED sets (see below).
#define MAX 6
// Defines distances when each LED set light up (green to red).
const int LED_THRESHOLDS[MAX] = { 100, 30, 25, 15, 12, 9 };
const int LED_PINS[MAX] = { 3, 4, 5, 6, 7, 8 };

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 9;
const int echoPin = 10;

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, INPUT );
  for ( int led = 0;  led < MAX;  ++led )
  {
    pinMode( LED_PINS[led], OUTPUT );
  }
  digitalWrite( 3, HIGH );
  lcd.setCursor( 0, 0 );
  lcd.print( "Parking System" );
  delay( 500 );
  lcd.setCursor( 0, 0 );
  lcd.print( "Ready........." );
}

// Determine distance to the vehicle & return it in cm.
// @return the calculated distance to the vehicle in cm
int getDistance()
{
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

// Show the given distance value using colored LCDs.
void lcdShowDistance( int distanceCm )
{
  lcd.setCursor(0, 0); // set to LCD upper left corner
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print( " cm  " );
  delay(10);
}

// Show the given distance value using colored LEDs.
// Dependencies:
//    LED_THRESHOLDS -indicates LED light up values;
// @param distanceCm -the distance value to use in
//                    choosing which LEDs are turned on.

void ledShowDistance( int distanceCm )
{
  for (int thisPin = 1; thisPin < MAX; thisPin++)
  {
    //turn off all pins except pin 1
    digitalWrite (LED_PINS[thisPin], LOW);
  }
  if (distanceCm > LED_THRESHOLDS[0])
  {
    return;
  }
  for (int  thresh = 1; thresh < MAX; thresh++)
  {
    if (distanceCm > LED_THRESHOLDS[thresh])
      return;
    digitalWrite (LED_PINS[thresh], HIGH);
  }
}

// Main Arduino Loop
void loop()
{
  int distance = getDistance();
  lcdShowDistance( distance );
  ledShowDistance( distance );
}
