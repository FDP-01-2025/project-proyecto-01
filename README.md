[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Carry the ball]

## Descripción del Proyecto

Este proyecto consiste en el juego que jugabamos en los telefonos de teclas llamado Sokaban, en el cual mezclamos estrategia y puzles, se juega utilizando las teclas "W" para arriba,"S" para abajo, "A" para la izquierda y "D" para la derecha. El juego utiliza estructuras de control como `if`, `switch`, y bucles `while` y `for` para generar interacciones dinámicas.

El jugador controla un personaje en un ambiente cerrado, con niveles predefinidos. La jugabilidad es de tipo puzzle lógico, donde debe planear los movimientos para colocar todas las cajas en su lugar. La dificultad aumenta en niveles sucesivos con diseños más complejos y obstáculos adicionales.

- Aplicación de los temas vistos:

Variables principales:
int playerX, playerY; para almacenar la posición del jugador.
int option; para la opción del menú.
vector<string> board; para representar el estado del nivel actual.
Variables constantes como char para símbolos del juego (WALL_VERTICAL, PLAYER).
Tipos de datos:
Uso de int para coordenadas y control del flujo.
Uso de string y vector<string> para guardar niveles y tablero.
char para símbolos visuales del entorno.

Estructuras condicionales (`if`, `else`, `switch`)
* `switch` (key) en el manejo de entradas para determinar la acción (mover en diferentes direcciones).
* `if-else` para verificar si el movimiento es válido, si hay una caja o si el nivel fue completado.
* `En move()`, condicionales que verifican el contenido de la celda destino y actualizan el tablero en consecuencia.

Ciclos (`for`, `while`, `do-while`)
* `for` en loadLevel() para recorrer toda la matriz y buscar la posición del jugador.
* `while` (true) en el bucle principal del juego para mantener la partida activa hasta que se resuelva o el jugador salga.
* `do-while` en el menú principal para repetir la selección de niveles y salir cuando se desee.

Funciones
Separación en funciones específicas:
* `loadLevel()` para cargar niveles.
* `displayBoard()` para mostrar el entorno.
* `move()` para gestionar los movimientos.
* `gameFinished()` para verificar si el jugador ganó.

 Estructuras de datos
* `vector<string>` para niveles y tablero, permitiendo fácil manipulación y expansión de niveles.
* Uso de `const char` para símbolos visuales, facilitando cambios estéticos.


 


## Equipo

- **Nombre del equipo:** [Proyecto 01]

### Integrantes del equipo

1. **Nombre completo:** [Cristal Abigail Claros Osorio]  
   **Carnet:** [00002525]


(Agregar más integrantes si es necesario)

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
