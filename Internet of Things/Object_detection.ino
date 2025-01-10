// When an object is detected within 30 cm, the system should activate a beeping sound and turn on the red LED.
// When the object is detected between 30 cm and 100 cm, the system should activate a beeping sound and turn on the green LED.
// When the object is detected at a distance greater than 100 cm, the system should turn on the blue LED and stop the beeping sound.

const int trigPin = 9;
const int echoPin = 10;
const int redLED = 3;
const int blueLED = 4;
const int greenLED = 5;
const int buzzer = 6;

long duration;
int distance;

void setup() {
  Serial.begin(9600);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH); 
  }
  else if (distance >= 10 && distance <= 20) {
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, LOW); 
  }
  else {
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW); 
  }
  
  delay(500);
}