const int interruptor = 2;
int contador = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(interruptor, INPUT);

  interrupts(); //Activamos las interrupciones
  attachInterrupt(digitalPinToInterrupt(interruptor), siempreLow, LOW); //Asignamos al pin 8 la interrupcion de tipo LOW (saltará siempre que esté a LOW) a la función siempreLOW
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DENTRO DE LOOP, contador lleva: ");
  Serial.println(contador);
  
  Serial.print("El interruptor tiene el valor: ");
  Serial.println(digitalRead(interruptor));

  delay(5000);
}

void siempreLow(){
  Serial.println("Estoy dentro de la interrupcion");
  contador++;
}
