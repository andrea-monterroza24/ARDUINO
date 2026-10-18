int LED = 23; 
int BOTON = 18; 

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);

  Serial.begin(115200);
}

void loop() {
  
  int estadoBoton = digitalRead(BOTON);

  if (estadoBoton == LOW) {
    digitalWrite(LED, HIGH);
    Serial.println( "Led encendido");
  } else {
    digitalWrite(LED, LOW);
    Serial.println( "Led apagado");
  }

  delay (2000); 

}
