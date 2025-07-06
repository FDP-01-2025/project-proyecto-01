#include <iostream>
#include <vector>
#include <conio.h> 

using namespace std;

//Tablero
const char PAREDl = '|';
const char PAREDa = '-';
const char VACIO = ' ';
const char CAJA = 'O';
const char DESTINO = '.';
const char PLAYER = '@';
const char CAJA_EN_DESTINO = '*'; 
const char PLAYER_EN_DESTINO = '+'; 

// Definir el tablero
vector<string> tablero = {
    "--------------",
    "|. O       . |",
    "|            |",
    "| @      O   |",
    "|            |",
    "|            |",
    "--------------"
},
     {
        "------------------",
        "|. O       .     |",
        "|                |",
        "| @      O       |",
        "|                |",
        "|                |",
        "|            O   |",
        "|  .             |",
        "-----------------"
    },
    {
        "----------------------------",
        "|.   O                   . |",
        "|                  .       |",
        "|  @   O                   |",
        "|                          |",
        "|                 O        |",
        "|  O                       |",
        "|                         .|",
        "----------------------------"
    },
    {
        "----------------------------",
        "|.   O                   . |",
        "|                  .       |",
        "|  @   O                   |",
        "|                          |",
        "|------           O        |",
        "|  O                       |",
        "|      |                  .|",
        "|      | O                .|",
        "----------------------------"
    }
;

// Coordenadas del jugador
int jugadorX = 2;
int jugadorY = 3;

// Función para mostrar el tablero
void mostrarTablero() {
    system("cls"); // Limpiar pantalla 
    for (const auto& fila : tablero) {
        cout << fila << endl;
    }
}

// Función para mover el jugador
void mover(int dx, int dy) {
    int x = jugadorX;
    int y = jugadorY;
    int nx = x + dx;
    int ny = y + dy;

    char objetivo = tablero[ny][nx];

    // Verificar si la casilla es un espacio vacío o un destino
    if (objetivo == VACIO || objetivo == DESTINO) {
      
        if (tablero[y][x] == PLAYER_EN_DESTINO)
            tablero[y][x] = DESTINO;
        else
            tablero[y][x] = VACIO;

        // Actualizar nueva posición
        if (objetivo == DESTINO)
            tablero[ny][nx] = PLAYER_EN_DESTINO;
        else
            tablero[ny][nx] = PLAYER;

        jugadorX = nx;
        jugadorY = ny;
    }
    // Verificar si hay una caja que se puede mover
    else if (objetivo == CAJA || objetivo == CAJA_EN_DESTINO) {
        int bx = nx + dx;
        int by = ny + dy;
        char objetivoCaja = tablero[by][bx];

        // Si la caja puede moverse
        if (objetivoCaja == VACIO || objetivoCaja == DESTINO) {
            // Mover caja
            if (objetivoCaja == DESTINO)
                tablero[by][bx] = CAJA_EN_DESTINO;
            else
                tablero[by][bx] = CAJA;

            // Mover jugador
            if (tablero[y][x] == PLAYER_EN_DESTINO)
                tablero[y][x] = DESTINO;
            else
                tablero[y][x] = VACIO;

            if (objetivo == CAJA_EN_DESTINO)
                tablero[ny][nx] = PLAYER_EN_DESTINO;
            else
                tablero[ny][nx] = PLAYER;

            jugadorX = nx;
            jugadorY = ny;
        }
    }
}

// Función para verificar si el juego ha terminado
bool finJuego() {
    for (int y = 0; y < tablero.size(); ++y) {
        for (int x = 0; x < tablero[y].size(); ++x) {
            if (tablero[y][x] == CAJA)
                return false;
        }
    }
    return true; 
}

int main() {
   int opcion;
    do {
        system("cls");
        cout << "=== Menu Principal ===" << endl;
        cout << "1. Jugar nivel 1" << endl;
        cout << "2. Jugar nivel 2" << endl;
        cout << "3. Jugar nivel 3" << endl;
        cout << "2. Jugar nivel 4" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1 || opcion == 2|| opcion == 3|| opcion == 4) {
            cargarNivel(niveles[opcion - 1], tablero, jugadorX, jugadorY);
   
 mostrarTablero();

    while (true) {
        char tecla = _getch(); 
        if (tecla == 27) // para salir
            break;
        switch (tecla) {
            case 'w':
            case 'W':
                mover(0, -1);
                break;
            case 's':
            case 'S':
                mover(0, 1);
                break;
            case 'a':
            case 'A':
                mover(-1, 0);
                break;
            case 'd':
            case 'D':
                mover(1, 0);
                break;
        }
        mostrarTablero();

        if (finJuego()) {
            cout << "¡Felicidades! Has completado el nivel." << endl;
            break;
        }
    }
    return 0;
}
