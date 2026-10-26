# Bill of Materials (BOM)

## Lista de materiales v1.0 (electrónica)

| Cantidad | Componente | Especificación | Fabricante | Código/SKU | Proveedor | Precio Unitario | Precio Total | Datasheet |
|---|---|---|---|---|---|---|---|---|
| 1 | Arduino UNO | ATmega328P, 5 V | Arduino | UNO R3 | [completar] | [CLP] | [CLP] | [URL] |
| 2 | Módulo de relé 1 canal | Bobina 5 V, contactos 10 A / 250 VAC - 30 VDC, activo con LOW | Songle | JQC3F-05VDC-C | [completar] | [CLP] | [CLP] | [URL] |
| 1 | Actuador lineal | 12 V DC, carrera 300 mm, 1500 N, 6 mm/s, ciclo 10 % | [completar] | ver etiqueta (…-405-300-C11) | [completar] | [CLP] | [CLP] | [URL] |
| 1 | Fuente de poder 12 V DC | Reemplazó al transformador original de 12 V DC 2 A, que venía defectuoso | [completar] | [completar] | [completar] | [CLP] | [CLP] | — |
| 2 | Pulsador táctil | 4 patitas, 6×6 mm | — | — | [completar] | [CLP] | [CLP] | — |
| 1 | Protoboard | 830 puntos | — | — | [completar] | [CLP] | [CLP] | — |
| — | Cables jumper macho-macho | Conexiones en la protoboard y al Arduino | — | — | [completar] | [CLP] | [CLP] | — |
| — | Cables jumper macho-hembra | Conexión a los pines VCC, GND e IN de los relés | — | — | [completar] | [CLP] | [CLP] | — |
| — | Cable de potencia rojo/negro | Para 12 V | — | — | [completar] | [CLP] | [CLP] | — |
| 1 | Cable USB A-B | Programación y alimentación del Arduino | — | — | [completar] | [CLP] | [CLP] | — |

## Materiales de construcción (definidos por el equipo)

| Cantidad | Material | Uso | Pieza(s) del modelo 3D | Proveedor | Precio Unitario | Precio Total |
|---|---|---|---|---|---|---|
| [completar] | Planchas de MDF (Trupán) | Paredes y placas del basurero | Chasis_Base, Contenedor_Basura, Tapa_Superior, Puerta_Frontal, Soporte_Actuador | [completar] | [CLP] | [CLP] |
| [completar] | Listones cuadrados de madera | Refuerzo estructural del chasis y el marco | Marco_Superior (4 postes) | [completar] | [CLP] | [CLP] |
| 1 | Lámina de metal | Placa compactadora | Placa_Compresora | [completar] | [CLP] | [CLP] |
| [completar] | Soportes y anclajes mecánicos | Fijación del actuador lineal | Soporte_Actuador | [completar] | [CLP] | [CLP] |
| [completar] | Bisagras estándar | Tapa y puerta | Bisagra_Tapa, Bisagra_Puerta | [completar] | [CLP] | [CLP] |
| [completar] | Manillas | Apertura de tapa y puerta | — (no modelado) | [completar] | [CLP] | [CLP] |
| [completar] | Imanes de neodimio pequeños | Cierre a presión de las puertas | Pestillo_Puerta (reemplazo) | [completar] | [CLP] | [CLP] |
| [completar] | Tornillos | Ensamble general | — (no modelado) | [completar] | [CLP] | [CLP] |
| [completar] | Adhesivos | Uniones de MDF y madera | — | [completar] | [CLP] | [CLP] |

### Diferencias entre la lista de materiales y el modelo 3D
- **Material:** el modelo usa acero en todas las piezas; la construcción real usa MDF, madera y una lámina de metal. Hay que actualizar los materiales en Fusion 360.
- **Ejes guía (Guias_Lineales):** están en el modelo, pero no en la lista de materiales. Definir de qué se harán (por ejemplo, varilla de acero o tubo de aluminio) o si se eliminan.
- **Placa compresora:** en el modelo es maciza de 1,5 cm; una lámina de metal es mucho más delgada. Ajustar el espesor en el modelo o indicar si la lámina va sobre una base de MDF.
- **Cierre de la puerta:** el modelo tiene un pestillo; la construcción usa imanes de neodimio.
- **Manillas y tornillos:** no están modelados.

ℹ️ **[INFORMACIÓN COMPLEMENTARIA AGREGADA] Peso estimado con los materiales reales**, usando las mismas medidas del modelo y densidades típicas (MDF ≈ 0,75 g/cm³; madera de pino ≈ 0,5 g/cm³):
- Piezas de MDF (12.081 cm³): ≈ **9,1 kg**
- Postes de madera (1.411 cm³): ≈ **0,7 kg**
- Total estructura sin placa ni actuador: ≈ **9,8 kg**, frente a 108,4 kg en acero.
El peso de la placa dependerá del espesor y tipo de la lámina.

## Estructura mecánica (según modelo de Fusion 360, material acero)

| Cantidad | Pieza | Medidas | Material en el modelo | Masa |
|---|---|---|---|---|
| 1 | Chasis base | 45 × 45 × 100 cm | Acero | 46,75 kg |
| 1 | Contenedor de basura | 39 × 39 × 55 cm | Acero | 15,63 kg |
| 4 | Postes del marco superior | 2 × 4 × 44,7 cm | Acero | 11,08 kg (total) |
| 1 | Tapa superior + bisagra | 45 × 45 × 1 cm | Acero | 16,16 kg |
| 1 | Puerta frontal + bisagra + pestillo | 39 × 0,3 × 52 cm | Acero | 5,07 kg |
| 1 | Placa compresora | 38 × 38 × 1,5 cm | Acero | 17,00 kg |
| 2 | Ejes guía | Ø1,6 × 59,7 cm | Acero | 1,88 kg (total) |
| 1 | Soporte del actuador | 39 × 39 × 1 cm | Acero | 11,81 kg |
| | **Total estructura (sin actuador)** | | | **125,38 kg** |

ℹ️ **[INFORMACIÓN COMPLEMENTARIA AGREGADA]** Componentes recomendados para versiones siguientes: resistencias de 220 Ω a 1 kΩ en la señal de cada botón (protección de pines), módulo reductor 12 V → 5 V (LM2596 o MP1584) para usar un solo enchufe, interruptor general en la línea de 12 V y una fuente de al menos 5 A para compactar con carga.

---

## Archivos a Incluir

- `bom_completo.xlsx` - Lista completa de materiales — **pendiente**
- `bom_completo.pdf` - Versión PDF para visualización — **pendiente**
- `datasheets/` - Carpeta con PDFs de componentes críticos — **pendiente**

---

## Presupuesto Total

**Costo Total Estimado:** $[XXXXX] CLP

### Desglose por Categoría
- Microcontrolador: $X,XXX
- Relés y botones: $X,XXX
- Actuador: $X,XXX
- Fuente de alimentación: $X,XXX
- Estructura/Encapsulado: $X,XXX
- Otros: $X,XXX
