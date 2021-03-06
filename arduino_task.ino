int temp_sensor = A1;
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(temp_sensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  int analogvalue;
  float temperature;
  analogvalue = analogRead(temp_sensor);
  temperature = float(analogvalue) / 1023;
  temperature = temperature * 500;
  Serial.println(temprature);
  delay(3000);
}
void blink() {
  state = !state;
  digitalWrite(ledPin, state);
  Serial.print("pressed") ;
  if(state==HIGH)
    {Serial.println("ON");}
  else
  {Serial.println("OFF");}
}
