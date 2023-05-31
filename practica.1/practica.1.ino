#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Conexiones
const int trigPin = 6;
const int echoPin = 7;
const int buzzerPin = 4;
const int relayPin = 5;
const int pauseButtonPin = 2;
const int pumpButtonPin = 3;

// Configuración de la pantalla LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables globales
volatile bool pauseProgram = false;
volatile bool pumpActivated = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(pauseButtonPin, INPUT_PULLUP);
  pinMode(pumpButtonPin, INPUT_PULLUP);

  // Configurar interrupciones
  attachInterrupt(digitalPinToInterrupt(pauseButtonPin), pauseInterrupt, LOW);
  attachInterrupt(digitalPinToInterrupt(pumpButtonPin), pumpInterrupt, LOW);

  // Inicializar la pantalla LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (!pauseProgram) {
    int distance = measureDistance();
    int percentage = map(distance, 0, 500, 500, 0); // Ajustar los valores según el tamaño del contenedor
    percentage = constrain(percentage, 0, 500);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nivel de agua: ");
    lcd.print(percentage);
    lcd.print("%");

    if (percentage >= 500) {
      digitalWrite(relayPin, LOW);
      delay(5000);
      alarm();
    } else {
      digitalWrite(relayPin, HIGH);
      noTone(buzzerPin);
      delay(5000);
    }

    if (pumpActivated) {
      digitalWrite(relayPin, LOW);
      delay(5000); // Tiempo para vaciar el contenedor, ajustar según sea necesario
      pumpActivated = false;
    }
  } else {
    alarm();
    digitalWrite(buzzerPin, HIGH);
    noTone(buzzerPin);
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0344 / 2;

  return distance;
}

void pauseInterrupt() {
  pauseProgram = !pauseProgram;
}

void pumpInterrupt() {
  pumpActivated = true;
}

void alarm() {
  // Sonido personalizado
  
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 587.33);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 523.25);
    delay(500);
    noTone(buzzerPin);
    delay(25);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 587.33);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 523.25);
    delay(500);
    noTone(buzzerPin);
    delay(25);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 587.33);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 523.25);
    delay(500);
    noTone(buzzerPin);
    delay(25);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 659.25);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 659.25);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    tone(buzzerPin, 493.88);
    delay(500);
    noTone(buzzerPin);
    delay(10);
    noTone(buzzerPin);
    delay(500);
  
 
}