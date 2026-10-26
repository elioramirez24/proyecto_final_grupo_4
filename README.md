# Recypress — Compactador automático de latas para puntos de reciclaje

### Información del Equipo
- **Integrantes:**
  - Santiago Harb - [prototipado y codigo]
  - Claudio Lagos - [diseño real ]
  - Sebastián Miranda - [diseño real]
  - Elio Ramírez - [prototipado y codigo]
  - Agustín Riquelme - [diseño real]
- **Curso:** Taller de Diseño (TEI201), Sección IV
- **Profesor:** Benjamín Gutiérrez

- **ODS Seleccionado:** ODS 12 - Producción y consumo responsables
- **Problema a resolver:** Desaprovechamiento de la capacidad de los contenedores de reciclaje debido al gran volumen que ocupan los residuos depositados sin compactar (latas, botellas PET y cartón). Caso de estudio del informe: Punto Verde Líder Quilín (Peñalolén). Usuarios del piloto según la presentación: comunidad de la UAI, escalable a puntos de reciclaje comunes.
- **Materiales de construcción:** MDF (Trupán), listones de madera y lámina de metal para la placa compactadora.

### Descripción del Proyecto
Basurero de reciclaje que incorpora un sistema de compactación mecánica automática. Un actuador lineal de 12 V, controlado por un Arduino UNO mediante dos relés, empuja una placa compresora que aplasta las latas dentro del contenedor. Así se reduce el volumen de cada residuo en el mismo momento en que el usuario lo deposita.

 una lata compactada hasta cerca del 30 % de su altura permite almacenar aproximadamente **tres veces más latas** en el mismo espacio (de 20 a 60 latas en una caja de 10,6 L).

El proyecto mejora un precedente del ramo Taller de Introducción a la Ingeniería (2.° semestre 2025), que usaba un compactador manual: requería esfuerzo físico, aplicaba una fuerza irregular y podía dañarse.

### Estado del Proyecto
- **Versión actual:** v1.0
- **Última actualización:** 25 de octubre de 2026
- **Estado:** Iteración 1 completada - El actuador sale y entra con los botones en banco de pruebas (Arduino UNO + 2 relés + fuente de 12 V).

---

##  Estructura del Repositorio
```
├── hardware/          # Circuitos, esquemas y BOM
├── software/          # Código Arduino y librerías
├── diseno_3d/        # Modelos Fusion 360 y renders
├── testing/          # Validación con usuarios
├── documentacion/    # Avances, reporte y presentación
└── iteraciones/      # Historial de versiones
```

---

##  Inicio Rápido

### Requisitos Previos
- Arduino IDE 2.x
- Fusion 360
- Arduino UNO, 2 módulos de relé de 5 V, actuador lineal de 12 V y fuente de 12 V DC

### Instalación
1. Clonar el repositorio.
2. No se requieren librerías externas.
3. Abrir `software/src/main/main.ino` en Arduino IDE, seleccionar **Arduino UNO** y el puerto correspondiente, y subir el código.
4. Armar el circuito siguiendo `hardware/instrucciones_ensamble.md` y hacer la prueba en seco (sin 12 V) antes de conectar la fuente.

---

##  Checklist de Entrega

### Hardware ✓
- [ ] Esquema del circuito (Fritzing/Wokwi) — *tabla de conexiones documentada; falta el diagrama*
- [ ] BOM completo — *componentes listados; faltan precios y proveedores*
- [x] Fotos del prototipo v1 (`iteraciones/iteracion_1/v1_fotos/`)

### Software ✓
- [x] Código comentado
- [x] Librerías documentadas (no usa librerías externas)
- [x] Manual de instalación

### Diseño 3D ✓
- [ ] Archivos Fusion 360 con TODOS los componentes — *estructura mecánica modelada y medida (135,4 kg); falta la electrónica*
- [ ] Renders de alta calidad (1+ ángulos)
- [ ] Planos técnicos

### Testing ✓
- [ ] Reporte de testing con usuarios (mín. 5)
- [ ] Evidencias fotográficas/videos
- [ ] Datos cuantitativos

### Documentación ✓
- [x] Avance N°1 (`documentacion/avances/`)
- [ ] Reporte final (máx. 15 páginas)
- [ ] Presentación (10 min)

---

##  Licencia
Este proyecto es desarrollado como parte del curso TEI201 - Facultad de Ingenieria y Ciencias - Universidad Adolfo Ibañez
