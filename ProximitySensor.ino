/*
  Blink Light as per proximity
*/

#define echoPin 2 // Echo Pin
#define trigPin 3 // Trigger Pin
#define green 0 // Trigger Pin
#define red 1 // Trigger Pin

long duration, cm, inches;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin (9600);
  // initialize digital pin LED_BUILTIN as an output.
  
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

// the loop function runs over and over again forever
void loop() {  
  Serial.print("start");
  Serial.println();

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

   cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  inches = (duration / 2) / 74; // Divide by 74 or multiply by 0.0135

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  lightLed(cm);
  delay(100);
  
}

void lightLed(long cm) {

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  
  if (cm < 20) {
    digitalWrite(red, HIGH);
    Serial.print("< 20");
  }
  if (cm < 100) {
    digitalWrite(green, HIGH);
    Serial.print("< 100");
  }
  else{
     digitalWrite(red, HIGH);
     delay(100);
     digitalWrite(red, LOW);
  }
}
