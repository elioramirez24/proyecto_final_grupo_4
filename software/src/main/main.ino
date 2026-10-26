/**
 * Proyecto: Compactador automático de latas (TEI201 - Taller de Diseño, UAI)
 * Versión:  v1.0 (Iteración 1)
 * Placa:    Arduino UNO
 *
 * Descripción:
 *   Controla un actuador lineal de 12 V con dos botones.
 *   - Mientras se mantiene presionado el botón SALIR, el actuador se extiende (compacta).
 *   - Mientras se mantiene presionado el botón ENTRAR, el actuador se retrae.
 *   - Al soltar ambos botones, o si se presionan los dos a la vez, el actuador se detiene.
 *
 * Tabla de pines (debe coincidir con el cableado real ANTES de subir el código):
 *   Pin 6 -> Botón SALIR  (protoboard j12; su otro extremo a10 va a GND)
 *   Pin 3 -> Botón ENTRAR (protoboard j22; su otro extremo a20 va a GND)
 *   Pin 4 -> IN del relé 1
 *   Pin 5 -> IN del relé 2
 *   NO USAR EL PIN 2: quedó dañado en la iteración 1 (ver iteraciones/iteracion_1/README.md).
 *
 * Librerías: ninguna externa.
 */

// ----- Pines -----
const int PIN_BOTON_SALIR  = 6;
const int PIN_BOTON_ENTRAR = 3;
const int PIN_RELE_1       = 4;
const int PIN_RELE_2       = 5;

// ----- Lógica de los módulos de relé -----
// Estos módulos se ACTIVAN con LOW y se apagan con HIGH (lógica inversa).
const int RELE_ENCENDIDO = LOW;
const int RELE_APAGADO   = HIGH;

void setup() {
  // Los botones usan la resistencia interna del Arduino (INPUT_PULLUP):
  // el pin queda en 5 V y, al presionar, el botón lo une a tierra (se lee LOW).
  // Nunca configurar como OUTPUT un pin conectado a un botón: eso dañó el pin 2.
  pinMode(PIN_BOTON_SALIR, INPUT_PULLUP);
  pinMode(PIN_BOTON_ENTRAR, INPUT_PULLUP);

  // Se fija el estado "apagado" antes de activar la salida,
  // para que los relés no se activen por un instante al encender.
  digitalWrite(PIN_RELE_1, RELE_APAGADO);
  digitalWrite(PIN_RELE_2, RELE_APAGADO);
  pinMode(PIN_RELE_1, OUTPUT);
  pinMode(PIN_RELE_2, OUTPUT);
}

void loop() {
  bool salirPresionado  = (digitalRead(PIN_BOTON_SALIR)  == LOW);
  bool entrarPresionado = (digitalRead(PIN_BOTON_ENTRAR) == LOW);

  if (salirPresionado && !entrarPresionado) {
    // Extender: primero se apaga el relé contrario para no activar ambos.
    digitalWrite(PIN_RELE_2, RELE_APAGADO);
    digitalWrite(PIN_RELE_1, RELE_ENCENDIDO);
  } else if (entrarPresionado && !salirPresionado) {
    // Retraer
    digitalWrite(PIN_RELE_1, RELE_APAGADO);
    digitalWrite(PIN_RELE_2, RELE_ENCENDIDO);
  } else {
    // Ningún botón o ambos: detener
    digitalWrite(PIN_RELE_1, RELE_APAGADO);
    digitalWrite(PIN_RELE_2, RELE_APAGADO);
  }
}
