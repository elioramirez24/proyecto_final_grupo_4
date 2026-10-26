# Instrucciones de ensamble - Sistema de control del actuador (v1.0)

Versión corregida de las instrucciones usadas en la iteración 1. Incorpora todas las correcciones encontradas durante las pruebas (ver `iteraciones/iteracion_1/README.md`).

**Resultado esperado:** mientras se mantiene presionado el botón SALIR, el actuador se extiende; mientras se mantiene presionado el botón ENTRAR, se retrae; al soltar, se detiene.

---

## Materiales
- 1 Arduino UNO con cable USB
- 2 módulos de relé de 5 V (JQC3F-05VDC-C), con pines VCC, GND e IN y borneras NO, COM y NC
- 2 pulsadores de 4 patitas
- 1 protoboard
- Cables jumper macho-macho (usar cables nuevos y probados)
- 1 actuador lineal de 12 V DC
- 1 transformador de 12 V DC (mínimo 2 A)
- 2 cables cortos pelados en ambas puntas (puentes entre relés)
- Destornillador pequeño y cinta aislante
- Multímetro (recomendado)

## Reglas antes de empezar
1. Desconectar el USB y el transformador antes de mover cualquier cable.
2. Los 12 V nunca deben tocar la protoboard ni el Arduino.
3. **No usar el pin 2 del Arduino** (quedó dañado en la iteración 1).

---

## Paso 1: Ubicar los botones
Los botones se colocan cruzando la canaleta central de la protoboard.
- **Botón SALIR:** patitas en e10, e12, f10 y f12.
- **Botón ENTRAR:** patitas en e20, e22, f20 y f22.

**Verificación:** ambos botones firmes y a horcajadas sobre la canaleta.

## Paso 2: Tierra y 5 V en la protoboard
- Cable del pin **GND** del Arduino → primer agujero de la columna **azul (−)** izquierda.
- Cable del pin **5V** del Arduino → primer agujero de la columna **roja (+)** izquierda.

**Verificación:** confirmar con la serigrafía del Arduino que el cable está en **5V** y no en el GND vecino.

## Paso 3: Cablear los botones (en diagonal)
| Desde | Hasta |
|---|---|
| a10 | Columna azul (−) |
| **j12** | **Pin 6** del Arduino |
| a20 | Columna azul (−) |
| **j22** | **Pin 3** del Arduino |

**Por qué en diagonal:** dentro del botón, las patitas de una misma fila están siempre unidas. Si la tierra y la señal se toman en la misma fila (por ejemplo, a10 y j10), el Arduino lee el botón como presionado todo el tiempo. En diagonal, la conexión solo se cierra al presionar.

## Paso 4: Alimentar los relés
- **VCC** de cada relé → columna roja (+).
- **GND** de cada relé → columna azul (−).

**Verificación:** con el USB conectado, se enciende la **luz roja** de ambos relés. Si no se enciende, revisar o reemplazar estos cables.

## Paso 5: Señal de los relés
- **IN** del relé 1 → **pin 4** del Arduino.
- **IN** del relé 2 → **pin 5** del Arduino.

## Paso 6: Lado de 12 V (con el transformador desenchufado)
Cada relé tiene tres tornillos. Leer las letras impresas junto a ellos: **NO**, **COM** (el del medio) y **NC**.

**Puente positivo:**
1. Insertar juntos el positivo del transformador y una punta de un cable corto en el **NO** del relé 1. Apretar.
2. Insertar la otra punta del cable corto en el **NO** del relé 2. Apretar.

**Puente negativo:**
1. Insertar juntos el negativo del transformador y una punta del otro cable corto en el **NC** del relé 1. Apretar.
2. Insertar la otra punta en el **NC** del relé 2. Apretar.

**Actuador:**
1. Un cable del actuador, **solo**, en el **COM** del relé 1.
2. El otro cable del actuador, **solo**, en el **COM** del relé 2.

| Tornillo | Relé 1 | Relé 2 |
|---|---|---|
| NO | +12 V | +12 V |
| COM | Cable 1 del actuador | Cable 2 del actuador |
| NC | −12 V | −12 V |

**Verificaciones:**
- **Misma posición, mismo polo en ambos relés.** Si el positivo queda arriba en un relé y abajo en el otro, los relés harán "clic" pero el actuador nunca se moverá.
- El tornillo debe apretar el **cobre**, no el plástico del cable. Pelar unos 5 mm.
- No deben quedar hilos de cobre sueltos que toquen el tornillo vecino.
- Tirar suavemente de cada cable: no debe salirse.

## Paso 7: Cargar el código
1. Conectar el Arduino al computador por USB.
2. Abrir Arduino IDE, borrar el contenido y pegar completo `software/src/main/main.ino`.
3. Confirmar que el código termine con dos llaves de cierre `}`.
4. Seleccionar **Arduino UNO** y el puerto. Presionar ✓ (Verificar) y luego → (Subir).

## Paso 8: Prueba en seco (sin 12 V)
Con el transformador **desenchufado**:
- **En reposo:** luz roja encendida y luz verde apagada en ambos relés.
- **Botón SALIR:** "clic" y luz verde en el relé 1 mientras se mantiene presionado.
- **Botón ENTRAR:** "clic" y luz verde en el relé 2 mientras se mantiene presionado.

Si algo no responde, subir `software/src/diagnostico/diagnostico.ino` y seguir la tabla de fallas de `hardware/README.md`.

## Paso 9: Prueba con 12 V
1. Dejar espacio libre para que el actuador se extienda (hasta 30 cm) y alejar las manos del vástago.
2. Con el USB conectado, enchufar el transformador **sin presionar nada**. El actuador debe quedar **quieto**. Si se mueve solo, desenchufar de inmediato y revisar el Paso 6.
3. Presionar el botón SALIR uno o dos segundos: el actuador debe extenderse. Si se retrae, desenchufar e intercambiar entre sí los dos cables del actuador en los COM.
4. Presionar el botón ENTRAR: el actuador debe retraerse.
5. Si algo suena raro, se calienta o huele a quemado, desenchufar primero el transformador.

**Comprobación con multímetro** (modo V⎓, rango 20, puntas sobre la cabeza de los tornillos COM de ambos relés):

| Situación | Lectura correcta |
|---|---|
| Sin presionar | 0 V |
| Botón SALIR | ≈ 12 V |
| Botón ENTRAR | ≈ −12 V |

Si sin presionar marca 12 V, los puentes están cruzados.

---

## Uso y cuidados
- Ciclo de trabajo del actuador: 10 %. Unos 9 minutos de descanso por cada minuto de uso.
- El actuador se mueve a unos 6 mm/s: recorrer 30 cm toma cerca de 50 segundos.
- ℹ️ **[INFORMACIÓN COMPLEMENTARIA AGREGADA]** Sin carga basta una fuente de 2 A; al compactar latas el consumo puede subir a 3-5 A.
