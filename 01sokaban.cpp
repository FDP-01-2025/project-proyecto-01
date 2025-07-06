#include <iostream>
#include <vector>
#include <conio.h> 

using namespace std;

// Símbolos del juego
const char PAREDl = '|';
const char PAREDa = '-';
const char VACIO = ' ';
const char CAJA = 'O';
const char DESTINO = '.';
const char PLAYER = '@';
const char CAJA_EN_DESTINO = '*'; 
const char PLAYER_EN_DESTINO = '+'; 

//ESTO
void cargarNivel(const vector<string>& nivel, vector<string>& tablero, int& jugadorX, int& jugadorY) {
    tablero = nivel;
    // Buscar posición del jugador
    for (int y = 0; y < tablero.size(); ++y) {
        for (int x = 0; x < tablero[y].size(); ++x) {
            if (tablero[y][x] == PLAYER || tablero[y][x] == PLAYER_EN_DESTINO) {
                jugadorX = x;
                jugadorY = y;
                return;
            }
        }
    }
}
//AQUI^

vector<string> tablero;
int jugadorX, jugadorY;

void mostrarTablero() {
    system("cls"); // Limpiar pantalla 
    for (const auto& fila : tablero) {
        cout << fila << endl;
    }
}

// Función para mover el jugador
void mover(int dx, int dy, vector<string>& tablero, int& jugadorX, int& jugadorY);
bool finJuego(const vector<string>& tablero);

// Niveles definidos
vector<vector<string>> niveles = {
    {
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
};




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

            // Bucle de juego
            while (true) {
                char tecla = _getch();
                if (tecla == 27) // para salir
                    break;
                switch (tecla) {
                    case 'w':
                    case 'W':
                        mover(0, -1, tablero, jugadorX, jugadorY);
                        break;
                    case 's':
                    case 'S':
                        mover(0, 1, tablero, jugadorX, jugadorY);
                        break;
                    case 'a':
                    case 'A':
                        mover(-1, 0, tablero, jugadorX, jugadorY);
                        break;
                    case 'd':
                    case 'D':
                        mover(1, 0, tablero, jugadorX, jugadorY);
                        break;
                }
                mostrarTablero();

                if (finJuego(tablero)) {
                    cout << "¡Felicidades! Has completado el nivel." << endl;
                    _getch(); // Pausa antes de volver al menú
                    break;
                }
            }
        }
    } while (opcion != 3);

    cout << "Gracias por jugar!" << endl;
    return 0;
}

// Implementación de mover y finJuego
void mover(int dx, int dy, vector<string>& tablero, int& jugadorX, int& jugadorY) {
    int x = jugadorX;
    int y = jugadorY;
    int nx = x + dx;
    int ny = y + dy;

    char objetivo = tablero[ny][nx];

    if (objetivo == VACIO || objetivo == DESTINO) {
        // Mover jugador
        if (tablero[y][x] == PLAYER_EN_DESTINO)
            tablero[y][x] = DESTINO;
        else
            tablero[y][x] = VACIO;

        if (objetivo == DESTINO)
            tablero[ny][nx] = PLAYER_EN_DESTINO;
        else
            tablero[ny][nx] = PLAYER;

        jugadorX = nx;
        jugadorY = ny;
    } else if (objetivo == CAJA || objetivo == CAJA_EN_DESTINO) {
        int bx = nx + dx;
        int by = ny + dy;
        char objetivoCaja = tablero[by][bx];

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

bool finJuego(const vector<string>& tablero) {
    for (const auto& fila : tablero) {
        for (char c : fila) {
            if (c == CAJA) return false;
        }
    }
    return true;
}
