const int ldr = A5;
const int led = 3;

const int MaxLDR = 1000;
const int MinLDR = 200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrValue = analogRead(ldr);
  //Los valores maximos y minimos han sido medidos con antelacion
  int valorLED = map(ldrValue, MinLDR, MaxLDR, 0, 255); //Se mapea la medida a la salida del led
  analogWrite(led, valorLED);
}
