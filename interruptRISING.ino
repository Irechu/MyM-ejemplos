const int interruptor = 2;
int contador = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(interruptor, INPUT);

  interrupts(); //Activamos las interrupciones
  attachInterrupt(digitalPinToInterrupt(interruptor), lowToHigh, RISING); //Asignamos al pin 8 la interrupcion de tipo CHANGE (saltará cada vez que cambie su valor de LOW a HIGH) a la función lowToHigh
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DENTRO DE LOOP, contador lleva: ");
  Serial.println(contador);
  
  Serial.print("El interruptor tiene el valor: ");
  Serial.println(digitalRead(interruptor));

  delay(10000);
}

void lowToHigh(){
  Serial.println("Estoy dentro de la interrupcion");
  contador++;
}
