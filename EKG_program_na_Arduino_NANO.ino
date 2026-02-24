// Opinowanie
#define LO_PLUS 11
#define LO_MINUS 10
#define ECG_PIN A0
#define LED_PIN LED_BUILTIN

// Średnia ruchoma - sposób filtracji sygnału
const int smoothWindow = 5;
int rawValues[smoothWindow];
int smoothIndex = 0;

// LED - parametry umożliwiające jego "miganie"
unsigned long lastBlink = 0;
bool ledState = false;

void setup() {
  Serial.begin(115200);

  pinMode(LO_PLUS, INPUT);
  pinMode(LO_MINUS, INPUT);
  pinMode(LED_PIN, OUTPUT);

  for (int i = 0; i < smoothWindow; i++) {
    rawValues[i] = 0;
  }
}

void loop() {

  // Powiąznie "migania" LED'u z podpięciem elektrod
  
  bool electrodesConnected =
    (digitalRead(LO_PLUS) == LOW && digitalRead(LO_MINUS) == LOW);

  if (electrodesConnected) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    if (millis() - lastBlink > 500) {
      lastBlink = millis();
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }

  int rawValue = analogRead(ECG_PIN);

  // Wygładzam sygnał
  rawValues[smoothIndex] = rawValue;
  smoothIndex = (smoothIndex + 1) % smoothWindow;

  int smoothedValue = 0;
  for (int i = 0; i < smoothWindow; i++) {
    smoothedValue += rawValues[i];
  }
  smoothedValue /= smoothWindow;

  // Wysyłam sygnał do komputera na port COM
  if (electrodesConnected) {
    Serial.println(smoothedValue);  // Wartości przyjmowane przez sygnał przy podpiętych elektrodach: 0–1023
  } else {
    Serial.println(-1);             // Wartości przyjmowane przez sygnał przy odpiętych elektrodach: -1
  }

  delay(10); // Częstotliwość: ~100 Hz
}

