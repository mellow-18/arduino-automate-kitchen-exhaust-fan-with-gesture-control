#define TRIG_PIN 9
#define ECHO_PIN 10
#define RELAY_PIN 7

long duration;
float distance;
bool fanState = false;
bool handPreviouslyDetected = false;
unsigned long lastToggleTime = 0;
const unsigned long debounceDelay = 1500; // 1.5 seconds between toggles

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Fan OFF initially
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // Hand detection range between ~5 cm and ~12 cm
  bool handDetected = (distance >= 5 && distance <= 12);

  // Only toggle when hand enters the zone and wasn't previously there
  if (handDetected && !handPreviouslyDetected) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastToggleTime >= debounceDelay) {
      fanState = !fanState;
      digitalWrite(RELAY_PIN, fanState ? HIGH : LOW);
      Serial.println(fanState ? "Fan ON" : "Fan OFF");
      lastToggleTime = currentMillis;
    }
  }

  // Update hand presence state
  handPreviouslyDetected = handDetected;

  delay(100); // Lower delay = more responsive
}
