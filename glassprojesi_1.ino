// Smart Glasses Project for Visually Impaired (0 CM Filter Version)

const int trigPin = 9;       
const int echoPin = 8;       
const int buzzerPin = 11;    

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Add timeout to prevent freezing if sensor fails
  duration = pulseIn(echoPin, HIGH, 30000);
  
  distance = duration / 58.2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // ERROR FILTER: If distance is 0 or invalid, turn buzzer off
  if (distance <= 0 || distance > 400) {
    noTone(buzzerPin);
  }
  // Real obstacle detection range (only 1 to 100 cm)
  else if (distance <= 30) {
    tone(buzzerPin, 2700);
    delay(80);
  } 
  else if (distance <= 60) {
    tone(buzzerPin, 2700);
    delay(200);
  } 
  else if (distance <= 100) {
    tone(buzzerPin, 2700);
    delay(400);
  } 
  else {
    noTone(buzzerPin);
  }
  
  delay(50);
}
