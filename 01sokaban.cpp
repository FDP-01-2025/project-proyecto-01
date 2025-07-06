#include <iostream>
#include <vector>
#include <conio.h> 

using namespace std;

// Game symbols
const char WALL_VERTICAL = '|';
const char WALL_HORIZONTAL = '-';
const char EMPTY = ' ';
const char BOX = 'O';
const char TARGET = '.';
const char PLAYER = '@';
const char BOX_ON_TARGET = '*'; 
const char PLAYER_ON_TARGET = '+'; 

// Load level function
void loadLevel(const vector<string>& level, vector<string>& board, int& playerX, int& playerY) {
    board = level;
    // Find player's position
    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[y].size(); ++x) {
            if (board[y][x] == PLAYER || board[y][x] == PLAYER_ON_TARGET) {
                playerX = x;
                playerY = y;
                return;
            }
        }
    }
}

vector<string> board;
int playerX, playerY;

void displayBoard() {
    system("cls"); // Clear screen
    for (const auto& row : board) {
        cout << row << endl;
    }
}

// Function to move the player
void move(int dx, int dy, vector<string>& board, int& playerX, int& playerY);
bool gameFinished(const vector<string>& board);

// Predefined levels
vector<vector<string>> levels = {
    {
        // Level 1
        "--------------",
        "|. O       . |",
        "|            |",
        "| @      O   |",
        "|            |",
        "|            |",
        "--------------"
    },
    {
        // Level 2
        "------------------",
        "|. O       .     |",
        "|                |",
        "| @      O       |",
        "|                |",
        "|                |",
        "|---         O   |",
        "|  .  |          |",
        "-----------------"
    },
    {
        // Level 3
        "----------------------------",
        "|.   O      |            . |",
        "|           |      .       |",
        "|  @   O                   |",
        "|                          |",
        "|                 O        |",
        "|  O      |                |",
        "|         |               .|",
        "----------------------------"
    },
    {
        // Level 4
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
    },
    {
        // Extreme Level 5
        "--------------------------------",
        "|   |                           |",
        "|@ .| O                       O |",
        "|                           ----|",
        "|                              .|",
        "| O                          . .|",
        "|     .                    |O |.|",
        "|---                      O     |",
        "| .                             |",
        "|----       O             ------|",
        "|  O                      |",
        "|                         |",
        "|-------------------------|", 
    }
};

int main() {
    int option;
    do {
        system("cls");
        cout << "=== Main Menu ===" << endl;
        cout << "1. Play Level 1" << endl;
        cout << "2. Play Level 2" << endl;
        cout << "3. Play Level 3" << endl;
        cout << "4. Play Level 4" << endl;
        cout << "5. Play Extreme Level" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;

        if (option >= 1 && option <= 5) {
            loadLevel(levels[option - 1], board, playerX, playerY);

            displayBoard();

            // Game loop
            while (true) {
                char key = _getch();
                if (key == 27) // Escape key to exit
                    break;
                switch (key) {
                    case 'w':
                    case 'W':
                        move(0, -1, board, playerX, playerY);
                        break;
                    case 's':
                    case 'S':
                        move(0, 1, board, playerX, playerY);
                        break;
                    case 'a':
                    case 'A':
                        move(-1, 0, board, playerX, playerY);
                        break;
                    case 'd':
                    case 'D':
                        move(1, 0, board, playerX, playerY);
                        break;
                }
                displayBoard();

                if (gameFinished(board)) {
                    cout << "Congratulations! You completed the level." << endl;
                    _getch(); // Pause before returning to menu
                    break;
                }
            }
        }
    } while (option != 6);

    cout << "Thanks for playing!" << endl;
    return 0;
}

// Implementation of move and gameFinished functions
void move(int dx, int dy, vector<string>& board, int& playerX, int& playerY) {
    int x = playerX;
    int y = playerY;
    int nx = x + dx;
    int ny = y + dy;

    char target = board[ny][nx];

    if (target == EMPTY || target == TARGET) {
        // Move player
        if (board[y][x] == PLAYER_ON_TARGET)
            board[y][x] = TARGET;
        else
            board[y][x] = EMPTY;

        if (target == TARGET)
            board[ny][nx] = PLAYER_ON_TARGET;
        else
            board[ny][nx] = PLAYER;

        playerX = nx;
        playerY = ny;
    } else if (target == BOX || target == BOX_ON_TARGET) {
        int bx = nx + dx;
        int by = ny + dy;
        char targetBox = board[by][bx];

        if (targetBox == EMPTY || targetBox == TARGET) {
            // Move box
            if (targetBox == TARGET)
                board[by][bx] = BOX_ON_TARGET;
            else
                board[by][bx] = BOX;

            // Move player
            if (board[y][x] == PLAYER_ON_TARGET)
                board[y][x] = TARGET;
            else
                board[y][x] = EMPTY;

            if (target == BOX_ON_TARGET)
                board[ny][nx] = PLAYER_ON_TARGET;
            else
                board[ny][nx] = PLAYER;

            playerX = nx;
            playerY = ny;
        }
    }
}

bool gameFinished(const vector<string>& board) {
    for (const auto& row : board) {
        for (char c : row) {
            if (c == BOX) return false; 
        }
    }
    return true;
}
