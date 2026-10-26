# Archivos Fusion 360

## Archivos

| Archivo | Descripción |
|---|---|
| `compactador_v1.f3z` | Ensamble "taller" exportado el 17-10-2026 (modelo iniciado el 21-09-2026) |

El formato `.f3z` incluye el diseño `.f3d` con sus referencias. Para abrirlo: Fusion 360 → **File > Open > Open from my computer** → seleccionar el `.f3z`.

---

## Estructura del Modelo (v1)

### Componentes (Components)
```
taller (Ensamble, Configuración 1)
├── Chasis_Base
├── Contenedor_Basura
├── Marco_Superior
├── Tapa_Superior
├── Puerta_Frontal
├── Placa_Compresora
├── Guias_Lineales
├── Soporte_Actuador
└── Actuador_Lineal
```

Material asignado a las piezas: **Acero** (7,85 g/cm³).

### Propiedades físicas por pieza (v1, medidas desde Fusion 360)

| Componente | Pieza | Medidas (X × Y × Z) | Volumen | Masa |
| --- | --- | --- | --- | --- |
| Chasis_Base | Chasis_Base | 45,0 × 45,0 × 100,0 cm | 5.955,41 cm³ | 46,75 kg |
| Contenedor_Basura | Contenedor_Basura | 39,0 × 39,0 × 55,0 cm | 1.991,05 cm³ | 15,63 kg |
| Marco_Superior | Poste_1 | 2,0 × 4,0 × 44,7 cm | 337,85 cm³ | 2,65 kg |
| Marco_Superior | Poste_2 | 2,0 × 4,0 × 44,7 cm | 357,60 cm³ | 2,81 kg |
| Marco_Superior | Poste_3 | 2,0 × 4,0 × 44,7 cm | 357,60 cm³ | 2,81 kg |
| Marco_Superior | Poste_4 | 2,0 × 4,0 × 44,7 cm | 357,60 cm³ | 2,81 kg |
| Actuador_Lineal | Actuador_Cuerpo | Ø4,0 × 53,5 cm (cilíndrico) | 672,30 cm³ | 5,28 kg |
| Actuador_Lineal | Actuador_Motor | 8,0 × 8,0 × 12,0 cm | 603,19 cm³ | 4,74 kg |
| Guias_Lineales | Eje_Guia_1 | Ø1,6 × 59,7 cm (cilíndrico) | 120,03 cm³ | 0,94 kg |
| Guias_Lineales | Eje_Guia_2 | Ø1,6 × 59,7 cm (cilíndrico) | 120,03 cm³ | 0,94 kg |
| Placa_Compresora | Placa_Compresora | 38,0 × 38,0 × 1,5 cm | 2.166,00 cm³ | 17,00 kg |
| Tapa_Superior | Tapa_Superior | 45,0 × 45,0 × 1,0 cm (agujero Ø1,5 cm) | 2.023,23 cm³ | 15,88 kg |
| Tapa_Superior | Bisagra_Tapa | 45,0 × 1,0 × 1,0 cm | 35,34 cm³ | 0,28 kg |
| Puerta_Frontal | Puerta_Frontal | 39,0 × 0,3 × 52,0 cm | 608,40 cm³ | 4,78 kg |
| Puerta_Frontal | Bisagra_Puerta | 1,0 × 1,0 × 39,0 cm | 30,63 cm³ | 0,24 kg |
| Puerta_Frontal | Pestillo_Puerta | 4,0 × 1,0 × 1,5 cm | 6,00 cm³ | 0,05 kg |
| Soporte_Actuador | Soporte_Actuador | 39,0 × 39,0 × 1,0 cm | 1.503,94 cm³ | 11,81 kg |
| **Total** | **17 piezas** | | **17.246,20 cm³** | **135,40 kg** |

### Observaciones de revisión
1. **Materiales del modelo distintos a los reales.** El modelo usa acero en todo, pero el equipo construirá con **MDF (Trupán)**, listones de madera y una lámina de metal para la placa (ver `hardware/bom/README.md`). Hay que cambiar los materiales en Fusion 360 para que el peso sea correcto. ℹ️ Con MDF y madera, la estructura sin placa ni actuador pasaría de unos 108 kg a cerca de **9,8 kg**.
2. **Placa compresora maciza de 15 mm.** Es la pieza más pesada después del chasis. ℹ️ El actuador debe levantarla en cada retroceso; una placa más delgada o con nervios de refuerzo reduciría el peso sin perder rigidez.
3. **Actuador modelado como sólido de acero (10,0 kg).** El actuador real es hueco y pesa bastante menos. Conviene asignarle su masa real (ver ficha del fabricante) para que el peso total sea correcto.
4. **Largo del actuador.** El modelo usa un cuerpo de 53,5 cm. ℹ️ El código del actuador real (…-405-300-…) sugiere un largo retraído cercano a 405 mm y una carrera de 300 mm; conviene medir el actuador físico y ajustar el modelo.
5. **Poste_1 con menor volumen** (337,85 cm³) que los otros tres (357,60 cm³), aunque tienen las mismas medidas. Revisar si tiene un corte o agujero que los demás no tienen, o si es un error de modelado.
6. **Agujero de Ø1,5 cm en la tapa.** Indicar su función. Si es para el paso del vástago del actuador, verificar que el diámetro del vástago real quepa.
7. **Holgura placa-contenedor:** 0,5 cm por lado (placa de 38 cm en contenedor de 39 cm). Es adecuada para que no roce, pero conviene confirmar que las latas no queden atrapadas en ese espacio.

### ⚠️ Componentes que faltan para cumplir el requisito del curso
El README de `diseno_3d/` exige que el modelo incluya **todos** los componentes del prototipo. El modelo actual tiene la estructura mecánica y el actuador, pero falta:
- [ ] Arduino UNO (68,6 × 53,4 mm)
- [ ] 2 módulos de relé
- [ ] Botones SALIR y ENTRAR en su ubicación exterior
- [ ] Transformador / fuente de 12 V
- [ ] Caja de protección de la electrónica
- [ ] Recorrido aproximado del cableado
- [ ] Tornillería y soportes de montaje

### Uniones (Joints)
[Documentar las juntas principales, en especial el movimiento lineal de la placa compresora sobre las guías]

### Parámetros
[Completar: dimensiones generales del contenedor, carrera útil de la placa, espesor de las placas]

---

## Versiones

| Versión | Fecha | Cambios Principales |
|---------|-------|---------------------|
| v1.0 | 17-10-2026 | Estructura mecánica con actuador lineal y placa compresora |
