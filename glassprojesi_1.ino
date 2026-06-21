// Görme Engelliler İçin Akıllı Gözlük Projesi (0 CM Filtreli Sürüm)

const int trigPin = 9;       
const int echoPin = 8;       
const int buzzerPin = 11;    

long sure;
int mesafe;

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
  
  sure = pulseIn(echoPin, HIGH);
  mesafe = sure / 58.2;
  
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");

  // HATA FİLTRESİ: Eğer mesafe 0 ise veya sensör okuyamadıysa buzzer'ı sustur
  if (mesafe <= 0 || mesafe > 1000) {
    noTone(buzzerPin);
  }
  // Gerçek engel algılama senaryoları (Sadece 1 ile 100 cm arası)
  else if (mesafe > 0 && mesafe <= 30) {
    tone(buzzerPin, 2700); 
    delay(100);
    noTone(buzzerPin);
    delay(50);
  } 
  else if (mesafe > 30 && mesafe <= 60) {
    tone(buzzerPin, 2700); 
    delay(200);
    noTone(buzzerPin);
    delay(200);
  } 
  else if (mesafe > 60 && mesafe <= 100) {
    tone(buzzerPin, 2700); 
    delay(400);
    noTone(buzzerPin);
    delay(500);
  } 
  else {
    noTone(buzzerPin);
  }
  
  delay(50);
}
