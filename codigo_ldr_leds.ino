
int LDR = 34;

int LED_R = 25;
int LED_A = 26;
int LED_V = 27;

const float UMBRAL_LUZ = 40.0;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_V, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int lecturaBits = analogRead(LDR);
  float porcentaje_luz = (lecturaBits / 4095.0) * 100.0;

  Serial.print("Lectura: ");
  Serial.print(lecturaBits);
  Serial.print(" | Porcentaje: ");
  Serial.print(porcentaje_luz);
  Serial.println("%");

  if (porcentaje_luz < UMBRAL_LUZ) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_V, HIGH);

    Serial.println("Poca luz, encendiendo LEDs");
  } else {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_V, LOW);

    Serial.println("Suficiente luz, apagando LEDs");
  }

  delay(1000);
}
