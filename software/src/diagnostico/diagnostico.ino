/**
 * Código de DIAGNÓSTICO - Compactador de latas (iteración 1)
 *
 * Uso: subir con el transformador de 12 V DESCONECTADO y abrir el Monitor Serie a 9600 baudios.
 *   1) Los relés se activan solos, uno a la vez, cada 2 segundos -> comprueba relés, cables IN y pines 4 y 5.
 *   2) El Monitor Serie muestra si cada botón está "suelto" o "PRESIONADO" -> comprueba botones y tierra.
 * Al terminar, volver a subir software/src/main/main.ino.
 */

const int PIN_BOTON_SALIR  = 6;
const int PIN_BOTON_ENTRAR = 3;
const int PIN_RELE_1       = 4;
const int PIN_RELE_2       = 5;

unsigned long ultimoCambio = 0;
int paso = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BOTON_SALIR, INPUT_PULLUP);
  pinMode(PIN_BOTON_ENTRAR, INPUT_PULLUP);
  digitalWrite(PIN_RELE_1, HIGH);   // HIGH = apagado en estos relés
  digitalWrite(PIN_RELE_2, HIGH);
  pinMode(PIN_RELE_1, OUTPUT);
  pinMode(PIN_RELE_2, OUTPUT);
}

void loop() {
  // Parte 1: alternar relés cada 2 segundos (apagados -> relé 1 -> relé 2)
  if (millis() - ultimoCambio > 2000) {
    ultimoCambio = millis();
    paso = (paso + 1) % 3;
    digitalWrite(PIN_RELE_1, paso == 1 ? LOW : HIGH);
    digitalWrite(PIN_RELE_2, paso == 2 ? LOW : HIGH);
  }

  // Parte 2: estado de los botones
  Serial.print("Boton salir: ");
  Serial.print(digitalRead(PIN_BOTON_SALIR) == LOW ? "PRESIONADO" : "suelto");
  Serial.print("   |   Boton entrar: ");
  Serial.println(digitalRead(PIN_BOTON_ENTRAR) == LOW ? "PRESIONADO" : "suelto");
  delay(200);
}
