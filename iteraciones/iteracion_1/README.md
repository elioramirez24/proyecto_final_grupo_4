# Iteración 1 - Concepto Inicial

## Información General

**Fecha:** Agosto - octubre 2026 (Avance N°1: 24-08-2026; pruebas de control: 18 y 19-10-2026)  
**Versión:** v1.0  
**Estado:** Prototipo alpha - Prueba de concepto  
**Avance asociado:** Avance #1

---

## Descripción

### Definición del problema
En la actividad de ideación (`documentacion/avances/00_Actividad_taller_ideacion.pdf`) se evaluaron dos problemáticas:
1. **Desperdicio masivo de comida** — solución: app de donación de excedentes o Arduino con sensor de temperatura y humedad que active un ventilador.
2. **Desborde de basura en las ciudades** — solución: basureros que compacten la basura o el reciclaje. ✅ **Elegida**

En el Avance N°1 (`documentacion/avances/01_Avance_Num_1.pdf`) el problema se acotó a: *el desaprovechamiento de la capacidad de los contenedores de reciclaje debido al volumen de residuos no compactados*, vinculado al **ODS 12**, con caso de estudio en el Punto Verde Líder Quilín (Peñalolén).

### Objetivo de esta iteración
- Validar que un Arduino pueda controlar el sentido de un actuador lineal de 12 V con dos botones.
- Probar el puente H con dos relés.
- Modelar la estructura mecánica del compactador en Fusion 360.

---

## Componentes Utilizados

### Hardware
- Microcontrolador: Arduino UNO
- Sensores: ninguno en esta versión (entrada manual por 2 pulsadores)
- Actuadores:
  - Actuador lineal 12 V DC, 300 mm, 1500 N, 6 mm/s
- Otros: 2 módulos de relé de 1 canal 5 V (JQC3F-05VDC-C), fuente de poder 12 V DC (reemplazó al transformador defectuoso), protoboard, cables macho-macho y macho-hembra, 2 pulsadores

### Software
- IDE: Arduino IDE 2.x
- Librerías: ninguna externa
- Versión código: v1.0 (`software/src/main/main.ino`)

---

## Fotos del Prototipo

| Archivo | Contenido |
|---|---|
| `v1_fotos/v1_vista_general.jpeg` | Montaje completo: actuador, Arduino, relés y protoboard |
| `v1_fotos/v1_circuito_protoboard.jpeg` | Botones y cableado en la protoboard |
| `v1_fotos/v1_arduino_uno.jpeg` | Conexiones en el Arduino UNO |
| `v1_fotos/v1_reles_primer_cableado.jpeg` | Primer cableado de los relés |
| `v1_fotos/v1_reles_puentes_cruzados.jpeg` | Detalle de las borneras donde se detectaron los puentes cruzados |
| `v1_fotos/v1_medicion_multimetro.jpeg` | Medición de voltaje de la fuente con multímetro |
| `v1_fotos/v1_arduino_fuente_nueva.jpg` | Arduino UNO junto a la nueva fuente de poder de 12 V |
| `v1_fotos/v1_circuito_protoboard_final.jpg` | Protoboard en su estado final funcionando |
| `v1_fotos/v1_reles_cableado_final.jpg` | Borneras de los relés en su estado final, con cinta aislante |

Video del diagnóstico del transformador: `testing/evidencias/videos/prueba_transformador_original_v1.mov`.

---

## Resultados de Testing Inicial

### Funcionalidad Lograda
✅ Lectura de ambos botones  
✅ Activación de cada relé con su botón (prueba en seco)  
✅ Movimiento del actuador en ambos sentidos con los 12 V (tras reemplazar la fuente)

### Problemas Identificados

1. **El código original no correspondía al circuito**
   - Descripción: ningún relé respondía a los botones.
   - Causa: el código controlaba los relés por los pines 2 y 3 (donde estaban los botones) y era una secuencia por tiempo que no leía los botones.
   - Solución: nuevo código con botones en `INPUT_PULLUP` y relés en los pines 4 y 5.

2. **Relés activados sin presionar**
   - Causa: señal y tierra del botón en la misma fila; esas patitas están unidas por dentro del botón.
   - Solución: tomar la señal en diagonal (j12 y j22).

3. **Lógica de relés invertida**
   - Descripción: luz verde encendida en reposo y apagada al presionar.
   - Causa: los módulos se activan con LOW.
   - Solución: constantes `RELE_ENCENDIDO = LOW` y `RELE_APAGADO = HIGH`.

4. **Relés sin energía**
   - Causa: cables jumper defectuosos en VCC y GND.
   - Solución: reemplazo de cables.

5. **Botón SALIR intermitente — pin 2 dañado**
   - Causa: el primer código enviaba 5 V por el pin 2 mientras el botón lo unía a tierra, lo que produjo un cortocircuito en el pin.
   - Solución: mover el botón al pin 6 y no volver a usar el pin 2.

6. **Revisión de los puentes de 12 V**
   - Descripción: al revisar las borneras se observó que la posición de los polos podía quedar distinta entre un relé y otro.
   - Regla establecida: cada posición (NO, COM, NC) debe tener el mismo polo en ambos relés.

7. **Problema principal: el actuador no se movía — transformador defectuoso**
   - Descripción: los botones y los relés funcionaban ("clic" y luz verde), pero el actuador no se movía en ningún sentido.
   - Causa: el transformador de 12 V venía con una falla de fábrica y no entregaba energía. El multímetro daba lecturas inestables o nulas en su salida.
   - Solución: reemplazarlo por otra fuente de poder que sí entrega los 12 V. Con ella, el actuador sale y entra correctamente.

---

## Aprendizajes

### Técnicos
- Antes de subir un código, verificar que sus pines coincidan con el cableado.
- Un pin conectado a un botón nunca debe configurarse como salida.
- Comprobar por partes: primero el lado de 5 V (prueba en seco), luego la fuente sola, luego el lado de 12 V.
- Probar la fuente con multímetro **antes** de buscar fallas en el circuito: un componente nuevo también puede venir defectuoso.
- El "clic" del relé confirma el control, pero no que la corriente llegue al actuador; eso se comprueba con el multímetro entre los COM.

### De Diseño
- La protoboard es poco confiable: la mayoría de las fallas fueron cables sueltos o defectuosos.
- La electrónica debe protegerse del contacto con las latas y los líquidos.

---

## Plan para Iteración 2

### Mejoras Planificadas

**Hardware:**
- [x] Completar la prueba del actuador con 12 V
- [ ] Medir el consumo de corriente al compactar una lata y confirmar que la nueva fuente lo soporta
- [ ] Agregar resistencias de 220 Ω - 1 kΩ en la señal de los botones
- [ ] Pasar el circuito de la protoboard a una placa perforada soldada
- [ ] Evaluar una fuente de ≥ 5 A para compactar con carga
- [ ] Evaluar un reductor 12 V → 5 V para usar un solo enchufe
- [ ] Agregar un interruptor general en la línea de 12 V

**Software:**
- [ ] Evaluar un modo de un solo toque (recorrido completo automático)
- [ ] Evaluar un sensor de presencia de lata, según la propuesta de la actividad de ideación

**Diseño:**
- [ ] Incorporar la electrónica al modelo de Fusion 360
- [ ] Diseñar la caja de protección de la electrónica
- [ ] Mejorar el ruteo de cables

---

## Archivos en esta Carpeta

- `v1_fotos/` - Fotografías del prototipo
- Código de esta versión: `software/src/main/main.ino`
- Conexiones: `hardware/esquemas/README.md`
- Modelo 3D: `diseno_3d/fusion360/compactador_v1.f3z`
