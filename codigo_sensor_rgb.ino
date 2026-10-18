int pinSensor = 34; 
int pin_R = 25;
int pin_V = 26; 
int pin_A = 27; 

void setup() {
  pinMode( pinSensor  , INPUT);
  pinMode( pin_R, OUTPUT); 
  pinMode( pin_V, OUTPUT);
  pinMode( pin_A, OUTPUT);  

  Serial.begin(115200);

}

void alarma(float a ){

    digitalWrite(pin_A, LOW);
    digitalWrite(pin_V, LOW);
    digitalWrite(pin_R, LOW);

  if(a <= 30){
    digitalWrite(pin_R, HIGH);
  }else if (a > 30 && a < 32){
    digitalWrite(pin_V, HIGH); 
  }else{
    digitalWrite(pin_A, HIGH); 
  }
}

void loop() {

  float voltaje = analogReadMilliVolts(pinSensor);
  float temperatura = voltaje/10;
  alarma(temperatura);
  Serial.print(temperatura); 
  Serial.println(" *C");
  delay(10000);


}