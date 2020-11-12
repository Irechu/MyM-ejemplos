#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
#include <DHT.h>


//
int modo = 0;

// DHT11
#define DHTTYPE DHT11
DHT dht(6, DHTTYPE);

// Bluetooth
SoftwareSerial BT1(2, 3); // RX | TX

// Definir constantes
#define ANCHO_PANTALLA 128 // ancho pantalla OLED
#define ALTO_PANTALLA 64 // alto pantalla OLED

// Objeto de la clase Adafruit_SSD1306
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, -1);

void setup() {

  //Inicializamos la pantalla
#ifdef __DEBUG__
  Serial.begin(9600);
  delay(100);
  Serial.println("Iniciando pantalla OLED");
#endif


  // Iniciar pantalla OLED en la dirección 0x3C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
#ifdef __DEBUG__
    Serial.println("No se encuentra la pantalla OLED");
#endif
    while (true);
  }

  // Inicializamos la interrupción
  interrupts();
  pinMode(2, INPUT);
  attachInterrupt(0, cambioModo, CHANGE);

  // Inicializamos el dth11
  //pinMode(6, INPUT);
  dht.begin();

  //Inicializamos el BT
  BT1.begin(9600);


}

void loop() {
  // Limpiar buffer
  display.clearDisplay();
  // Tamaño del texto
  display.setTextSize(2);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(10, 20);
  //dht11
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  switch (modo) {
    case 0:
      display.println("inicio");
      break;
    case 1:
      display.setTextSize(1);
      display.println("Temperatura ");
      display.setTextSize(2);
      display.setCursor(10, 40);
      display.println(t);
      break;
    case 2:
      display.setTextSize(1);
      display.println("Humedad ");
      display.setTextSize(2);
      display.setCursor(10, 40);
      display.println(h);
      break;
  }

  // Enviar a pantalla
  display.display();

}

// ISR
void cambioModo() {
  if (BT1.available()) {
    char dato = BT1.read();
    Serial.println("entra en la interrupcion");
    if (dato == 't') {
      modo = 1;

    } else if (dato == 'h') { 
      modo = 2;
    }
  }
}
