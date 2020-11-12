# MyM-ejemplos
Aquí encontarremos diferentes ejemplos usados para la asignatura Microprocesadores y Microcontroladores.
Consisten en codigos de ejemplo para mostrar de manera práctica el funcionamiento de las **interrupciones** y el **PWM**
- Interrupciones:
  - LOW: tendremos en la rutina de interrupción un print que nos indica que está a LOW, mientras esté el valor del pin a 0, no saldrá de la rutina.
  - RISING/FALLING: Usamos un interruptor para mostrar que entra en la rutina de interrupción cuando se hace el cambio de flanco cerrespondiente.
  - CHANGE: Usamos un modulo bluetooth para mandar una señal a un pin, este al detectar un cambio en el flanco cambiará el modo de visualización de la pantalla. En esta se muestran los datos de humedad o de temperatura, según este modo, tomados por un dht11.
- PWM
  - Ejemplo 1: usaremos una LDR, si hay poca luz en el ambiente, se encenderá más el LED
  - Ejemplo 2: usaremos un buzzer y el PWD para realizar diferentes sonidos.
