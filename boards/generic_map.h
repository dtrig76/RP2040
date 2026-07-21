/*
 * Mapeo de hardware personalizado para Raspberry Pi Pico (CNC)
 * Configuración directa a convertidores lógicos de 5V
 */

// 1. Pines de Paso (PUL / STEP)
// Concepto: grblHAL utiliza la máquina de estados PIO del RP2040.
// Lógica: Al definir la base en 2, el sistema asigna automáticamente y de 
// forma consecutiva X al pin 2, Y al pin 3, y Z al pin 4.
#define STEP_PORT           GPIO_PIO  
#define STEP_PINS_BASE      2         

// 2. Pines de Dirección (DIR)
// Función: Controla la polaridad para determinar si la herramienta 
// se mueve hacia las coordenadas positivas o negativas.
#define DIRECTION_PORT      GPIO_OUTPUT
#define X_DIRECTION_PIN     5
#define Y_DIRECTION_PIN     6
#define Z_DIRECTION_PIN     7
#define DIRECTION_OUTMODE   GPIO_SHIFT5

// 3. Pines de Habilitación (ENA) Independientes
// Lógica: Se elimina la constante "STEPPERS_ENABLE_PIN" (global) y se 
// declaran variables independientes por eje. Esto aísla eléctricamente 
// cada driver TB6600, previniendo cortocircuitos.
#define ENABLE_PORT         GPIO_OUTPUT
#define X_ENABLE_PIN        8
#define Y_ENABLE_PIN        9
#define Z_ENABLE_PIN        10

// Notas para finales de carrera: Como los desactivamos físicamente, 
// puedes comentarlos en el código original o moverlos a pines libres (ej. 11, 12, 13).
// //#define X_LIMIT_PIN    11

// 4. Pin de Sonda (Touch Probe)
// Función: Entrada digital auxiliar para detectar el cero de la pieza en el eje Z.
#define AUXINPUT2_PIN       28 
#define PROBE_PIN           AUXINPUT2_PIN
