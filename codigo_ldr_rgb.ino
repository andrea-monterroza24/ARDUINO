int LDR = 34;

int LED_R = 25;
int LED_V = 26;  // Verde
int LED_A = 27;  // Azul

void setup() {
  Serial.begin(115200);

  pinMode(LED_R, OUTPUT);
  pinMode(LED_V, OUTPUT);
  pinMode(LED_A, OUTPUT);
}

void loop() {
  int lecturaBits = analogRead(LDR);
  float porcentajeLuz = (lecturaBits / 4095.0) * 100.0;

  Serial.print("Lectura: ");
  Serial.print(lecturaBits);
  Serial.print(" | Luz: ");
  Serial.print(porcentajeLuz);
  Serial.println("%");

  // Apagar los tres colores antes de elegir el nuevo
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_V, LOW);
  digitalWrite(LED_A, LOW);

  if (porcentajeLuz < 20) {
    // Color rojo
    digitalWrite(LED_R, HIGH);
    Serial.println("Color: ROJO");

  } else if (porcentajeLuz < 40) {
    // Rojo + verde = amarillo
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_V, HIGH);
    Serial.println("Color: AMARILLO");

  } else if (porcentajeLuz < 60) {
    // Color verde
    digitalWrite(LED_V, HIGH);
    Serial.println("Color: VERDE");

  } else if (porcentajeLuz < 80) {
    // Verde + azul = cian
    digitalWrite(LED_V, HIGH);
    digitalWrite(LED_A, HIGH);
    Serial.println("Color: CIAN");

  } else {
    // Color azul
    digitalWrite(LED_A, HIGH);
    Serial.println("Color: AZUL");
  }

  delay(500);
}
