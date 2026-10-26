# Esquemas de Circuito

## Archivos Requeridos

### Formato Fritzing
- `circuito_completo.fzz` - Archivo fuente Fritzing — **pendiente**
- `esquema_circuito.png` - Exportación del esquema — **pendiente**

### Formato Wokwi
- `wokwi_diagram.json` - Archivo de proyecto Wokwi — **pendiente**
- `wokwi_screenshot.png` - Captura del circuito — **pendiente**
- `wokwi_link.txt` - URL del proyecto online — **pendiente**

Mientras no esté el diagrama, la tabla siguiente documenta el circuito v1.0 tal como quedó funcionando.

---

## Conexiones v1.0

### Lado de control (5 V)

| Desde | Hasta | Función |
|---|---|---|
| Arduino **5V** | Columna roja (+) de la protoboard | Alimenta los relés |
| Arduino **GND** | Columna azul (−) de la protoboard | Tierra común de botones y relés |
| Protoboard **a10** | Columna azul (−) | Tierra del botón SALIR |
| Protoboard **j12** | Arduino **pin 6** | Señal del botón SALIR (diagonal a a10) |
| Protoboard **a20** | Columna azul (−) | Tierra del botón ENTRAR |
| Protoboard **j22** | Arduino **pin 3** | Señal del botón ENTRAR (diagonal a a20) |
| Relé 1 y relé 2 **VCC** | Columna roja (+) | Energía de los relés |
| Relé 1 y relé 2 **GND** | Columna azul (−) | Tierra de los relés |
| Relé 1 **IN** | Arduino **pin 4** | Orden de activación del relé 1 |
| Relé 2 **IN** | Arduino **pin 5** | Orden de activación del relé 2 |

Botones: botón SALIR en e10, e12, f10, f12; botón ENTRAR en e20, e22, f20, f22, cruzando la canaleta central. La señal se toma **en diagonal** respecto de la tierra porque las patitas de una misma fila están unidas internamente; si se toman en la misma fila, el Arduino lee el botón como presionado todo el tiempo.

### Lado de potencia (12 V) — puente H con dos relés

| Tornillo | Relé 1 | Relé 2 |
|---|---|---|
| **NO** | +12 V (fuente) | +12 V (puente desde relé 1) |
| **COM** (medio) | Cable 1 del actuador, solo | Cable 2 del actuador, solo |
| **NC** | −12 V (fuente) | −12 V (puente desde relé 1) |

**Regla:** cada posición debe tener el mismo polo en ambos relés.

### Por qué funciona
- **En reposo**, ambos COM tocan el negativo (NC): los dos extremos del actuador tienen el mismo polo, no circula corriente y el actuador queda quieto.
- **Relé 1 activo**: su COM pasa a +12 V. La corriente va de +12 V → actuador → −12 V y el actuador sale.
- **Relé 2 activo**: la corriente circula en sentido contrario y el actuador entra.
- Si el actuador se mueve al revés, se intercambian entre sí los dos cables del actuador en los COM.

---

## Notas de Diseño
- Hay **dos fuentes separadas**: el USB (5 V) alimenta el Arduino y el lado de control de los relés; el transformador de 12 V alimenta solo el actuador a través de los contactos de los relés. Dentro de cada relé ambos lados están aislados, por eso el computador puede quedar conectado durante las pruebas.
- Los 12 V nunca deben conectarse al Arduino ni a la protoboard.
