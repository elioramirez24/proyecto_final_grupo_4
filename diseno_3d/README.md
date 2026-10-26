# Diseño 3D - Documentación

## ⚠️ REQUISITO CRÍTICO

El modelo 3D debe incluir **TODOS** los componentes del prototipo:
- ✅ Encapsulado exterior completo
- ✅ Placa ESP32/Arduino (con dimensiones exactas)
- ✅ Todos los sensores en posición de instalación
- ✅ Todos los actuadores
- ✅ Batería / fuente de alimentación
- ✅ Cableado (routing aproximado)
- ✅ Sistema de montaje (brackets, tornillos)
- ✅ Orificios de ventilación (si aplica)

**NO ES ACEPTABLE:** Solo el encapsulado vacío sin componentes internos

---

## Carpetas

#### `fusion360/`
Archivos nativos de Fusion 360 (.f3d)

#### `renders/`
Imágenes renderizadas de alta calidad

#### `planos/`
Planos técnicos con cotas

---

## Especificaciones

**Software:** Autodesk Fusion 360  
**Unidades:** Milímetros (mm)  
**Escala:** 1:1 (dimensiones reales)

**Dimensiones externas:** 450 mm × 450 mm × 1000 mm (envolvente del chasis base)  
**Volumen de material:** 17.246 cm³ (suma de las 17 piezas)  
**Peso estimado (modelo v1):** 135,4 kg con todas las piezas en acero (densidad 7,85 g/cm³)  
**Material:** Acero en el modelo actual. Materiales reales de construcción: MDF (Trupán), listones de madera y lámina de metal para la placa compactadora (ver `hardware/bom/README.md`). ℹ️ Con MDF y madera, la estructura sin placa ni actuador pesaría cerca de 9,8 kg.

El detalle por pieza está en `fusion360/README.md`.

---

## Consideraciones de Diseño

### Funcionales
- [ ] Acceso a puertos USB/alimentación
- [ ] Ventilación adecuada
- [ ] Protección de componentes
- [ ] Fácil acceso para mantenimiento
- [ ] Resistencia a condiciones ambientales

### Fabricación
- [ ] Imprimible sin soportes excesivos
- [ ] Tolerancias de ensamble (+0.2mm)
- [ ] Grosor de pared mínimo 2mm
- [ ] Sin ángulos imposibles (overhangs <45°)

---

## Configuración de Impresión 3D (si fue utilizada)

**Impresora:** [Modelo]  
**Material:** [PLA/ABS/PETG]  
**Calidad de capa:** 0.2mm  
**Relleno:** 20-30%  
**Soportes:** [Sí/No - dónde]  
**Temperatura nozzle:** [°C]  
**Temperatura cama:** [°C]  
**Velocidad:** [mm/s]

**Tiempo estimado de impresión:** [X horas]  
**Peso de material:** [X gramos]
