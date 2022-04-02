int led = 8; // initializing the led pin 8
int Reed = 13; // initializing the magnetic reed sensor data pin
int triggerPin = 9; // trigger pin to trigger the ultrasonic sensor
int echoPin = 7; //echo pin to check for the feedback
int distance = 0; 
unsigned long currentTime;
unsigned long previousTime;
unsigned long duration = 15000;//15000;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(Reed, INPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  // pin definition
  // and the buad rate for the serial monitor is set
}

void loop()
{
  currentTime = millis(); // currentTime variable refers to the time since code execution
  triggerUltraSonicSensor(100);
  // trigger UltraSonic sensor function sets the trigger for the sensor on and off
  if(currentTime - previousTime >= duration)
  {
    //after 15 seconds the data from the sensor is printed to the serial monitor
    previousTime = currentTime;
    Serial.print(distance);
    Serial.print("###");
    Serial.print(digitalRead(Reed));
    Serial.println();   
  }
  // these if conditional checks the reading of the reed switch sensor
  if(digitalRead(Reed) == 1)
  {
    digitalWrite(led, 1); 
  }
  else
  {
    digitalWrite(led, 0); 
  }
 
}

void triggerUltraSonicSensor(int switchingRate)
{
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(switchingRate);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(switchingRate);
  distance = pulseIn(echoPin, HIGH)/58;
}
