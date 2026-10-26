# Hardware - Documentación

## Contenido
Esta carpeta contiene toda la documentación técnica del hardware del proyecto.

### 📁 Carpetas

#### `esquemas/`
Diagramas de circuitos y tabla de conexiones del sistema

#### `bom/`
Bill of Materials (Lista de materiales)

#### `fotos/`
Fotografías del prototipo (las de la v1.0 están en `iteraciones/iteracion_1/v1_fotos/`)

---

## Instrucciones de Ensamble

### Componentes Principales
1. **Arduino UNO** - Lee los botones y decide qué relé activar.
2. **2 módulos de relé de 5 V (JQC3F-05VDC-C)** - Interruptores que conectan los 12 V al actuador; juntos forman un puente H que permite invertir el sentido de giro del motor.
3. **Actuador lineal 12 V DC, 300 mm, 1500 N** - Empuja la placa compresora.
4. **Fuente de poder 12 V DC** - Alimenta el actuador. (El transformador original de 2 A venía defectuoso y fue reemplazado.)
5. **2 pulsadores de 4 patitas** - Botón SALIR (compactar) y botón ENTRAR (volver).
6. **Protoboard y cables macho-macho y macho-hembra** - Conexiones del lado de control.

### Pasos de Ensamblaje
Instrucciones completas y verificadas: `instrucciones_ensamble.md`. Resumen:

1. Ubicar los botones cruzando la canaleta central de la protoboard (filas 10-12 y 20-22).
2. Conectar el GND del Arduino a la columna azul (−) y el 5V a la columna roja (+).
3. Cablear cada botón en diagonal: tierra en la columna a y señal en la columna j de la fila opuesta.
4. Alimentar los relés (VCC a la columna roja, GND a la azul) y conectar sus IN a los pines 4 y 5.
5. Conectar los 12 V a los relés según la tabla de `esquemas/README.md`.
6. Subir `software/src/main/main.ino`.
7. **Prueba en seco** con la fuente desenchufada: cada botón debe producir el "clic" de su relé y encender su luz verde.
8. Enchufar la fuente y probar el movimiento del actuador.

### Precauciones
- ⚠️ Desconectar el USB y el transformador antes de mover cualquier cable.
- ⚠️ Ningún cable pelado de 12 V debe tocar la protoboard, el Arduino ni sus cables.
- ⚠️ Recortar los hilos de cobre sueltos en las borneras para evitar cortocircuitos entre tornillos vecinos.
- ⚠️ Mantener las manos lejos del vástago: el actuador avanza hasta 300 mm con 1500 N.
- ⚠️ Respetar el ciclo de trabajo del actuador (10 %): unos 9 minutos de descanso por cada minuto de uso.

---

## Especificaciones Técnicas

**Alimentación control:** 5 V por USB (computador, cargador o power bank)  
**Alimentación potencia:** 12 V DC (fuente de poder; amperaje: [completar])  
**Actuador:** 12 V DC, carrera 300 mm, carga máx. 1500 N, velocidad 6 mm/s, ciclo de trabajo 10 %  
**Consumo:** [medir] — ℹ️ cerca de 1 A sin carga; bajo carga cercana a 1500 N puede requerir 3 a 5 A  
**Dimensiones del basurero (modelo v1):** 45 × 45 × 100 cm  
**Peso (modelo v1, todo en acero):** 135,4 kg — ver `diseno_3d/fusion360/README.md`

---

## Troubleshooting

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| Los relés no hacen nada al presionar | El código usaba los pines de los botones como salidas y nunca leía los botones | Usar `main.ino` (pines y `INPUT_PULLUP` correctos) |
| Un relé se activa solo, sin presionar | Señal y tierra del botón en la misma fila (patitas unidas internamente) | Tomar la señal en diagonal: j12 y j22 |
| Luz verde encendida en reposo y se apaga al presionar | Módulos de relé con lógica inversa (activos con LOW) | `RELE_ENCENDIDO = LOW`, `RELE_APAGADO = HIGH` |
| Luz roja del relé apagada | Sin 5 V: cable VCC/GND defectuoso o en el pin equivocado | Reemplazar los cables y verificar 5V → columna roja |
| Un botón funciona a ratos | Pin 2 dañado por cortocircuito con el primer código | Usar el pin 6 |
| Fallan ambos botones a la vez | Cable GND del Arduino a la columna azul suelto o dañado | Reemplazar ese cable |
| Relés hacen "clic" pero el actuador no se mueve | Puentes cruzados entre relés (positivo arriba en uno y abajo en el otro) | Misma posición = mismo polo en ambos relés |
| El actuador no se mueve con un botón | Ya está en su extremo de recorrido | Presionar el botón contrario |
| Los relés funcionan pero el actuador no se mueve en ningún sentido | Transformador defectuoso: no entrega energía | Medir la salida con multímetro; reemplazar la fuente |
| El multímetro marca 12 V solo por un instante | Las puntas apenas rozan el cobre | Medir apoyando la punta en la cabeza del tornillo |
