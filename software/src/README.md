# Código Fuente

## Archivos

| Archivo | Función |
|---|---|
| `main/main.ino` | Programa principal: mueve el actuador mientras se mantiene presionado cada botón |
| `diagnostico/diagnostico.ino` | Prueba de relés y botones por separado (Monitor Serie a 9600 baudios) |

Cada programa está en su propia carpeta porque Arduino IDE exige que el archivo `.ino` esté dentro de una carpeta con su mismo nombre.

---

## Tabla de pines (v1.0)

| Pin Arduino | Conectado a | Modo en el código |
|---|---|---|
| 6 | Botón SALIR (protoboard j12) | `INPUT_PULLUP` |
| 3 | Botón ENTRAR (protoboard j22) | `INPUT_PULLUP` |
| 4 | IN del relé 1 | `OUTPUT` |
| 5 | IN del relé 2 | `OUTPUT` |
| 2 | **No usar** (dañado en la iteración 1) | — |

Los módulos de relé usados se activan con **LOW** y se apagan con **HIGH**. Esto está definido en las constantes `RELE_ENCENDIDO` y `RELE_APAGADO`.

---

## Funcionamiento de `main.ino`

| Botón SALIR | Botón ENTRAR | Relé 1 | Relé 2 | Actuador |
|---|---|---|---|---|
| Suelto | Suelto | Apagado | Apagado | Detenido |
| Presionado | Suelto | Encendido | Apagado | Sale (compacta) |
| Suelto | Presionado | Apagado | Encendido | Entra (vuelve) |
| Presionado | Presionado | Apagado | Apagado | Detenido |

Antes de encender un relé se apaga el otro, para que nunca queden ambos activos por error. El actuador incluye finales de carrera internos que lo detienen al llegar al extremo de su recorrido.

---

## Estándares de Código

### Comentarios
```cpp
// Comentarios en español
// Explicar QUÉ hace y POR QUÉ (no solo el CÓMO)
```

### Nombres de Variables
- Variables: `camelCase`
- Constantes: `UPPER_SNAKE_CASE`
- Funciones: `camelCase()`

---

## Reglas para evitar daños (aprendidas en la iteración 1)
- Verificar que los números de pin del código coincidan con el cableado **antes** de subirlo.
- Nunca configurar como `OUTPUT` un pin conectado a un botón.
- Hacer siempre la prueba en seco (sin 12 V) después de cualquier cambio.
