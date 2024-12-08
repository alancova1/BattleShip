#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int GRID_SIZE = 5;
const int NUM_SHIPS = 3;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void displayGrid(char grid[GRID_SIZE][GRID_SIZE], bool revealShips);
void placeShips(char grid[GRID_SIZE][GRID_SIZE], int numShips);
bool isValidGuess(char grid[GRID_SIZE][GRID_SIZE], int row, int col);
bool checkHit(char grid[GRID_SIZE][GRID_SIZE], int row, int col);
bool allShipsSunk(char grid[GRID_SIZE][GRID_SIZE]);

int main() {
    srand(time(0));

    char grid[GRID_SIZE][GRID_SIZE];
    initializeGrid(grid);
    placeShips(grid, NUM_SHIPS);

    cout << "Welcome to Battleship!" << endl;
    cout << "Try to sink all the computer's ships on a " << GRID_SIZE << "x" << GRID_SIZE << " grid.\n" << endl;

    int remainingShips = NUM_SHIPS;
    int guessRow, guessCol;
    int attempts = 0;

    while (remainingShips > 0) {
        displayGrid(grid, false);
        cout << "\nEnter your guess (row and column, 0-" << GRID_SIZE-1 << "): ";
        cin >> guessRow >> guessCol;

        if (!isValidGuess(grid, guessRow, guessCol)) {
            cout << "Invalid guess or already guessed! Try again." << endl;
            continue;
        }

        attempts++;
        if (checkHit(grid, guessRow, guessCol)) {
            cout << "Hit! You sunk a ship!" << endl;
            grid[guessRow][guessCol] = 'X';
            remainingShips--;
        } else {
            cout << "Miss!" << endl;
            grid[guessRow][guessCol] = 'O';
        }

        if (allShipsSunk(grid)) {
            cout << "\nCongratulations! You sunk all the ships in " << attempts << " attempts!" << endl;
            break;
        }
    }

    displayGrid(grid, true);
    cout << "Thanks for playing Battleship!" << endl;
    return 0;
}

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '~';
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], bool revealShips) {
    cout << "\n   ";
    for (int i = 0; i < GRID_SIZE; i++) cout << i << " ";
    cout << "\n  ";
    for (int i = 0; i < GRID_SIZE; i++) cout << "--";
    cout << endl;

    for (int i = 0; i < GRID_SIZE; i++) {
        cout << i << " |";
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S' && !revealShips) {
                cout << "~ ";
            } else {
                cout << grid[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void placeShips(char grid[GRID_SIZE][GRID_SIZE], int numShips) {
    int shipsPlaced = 0;
    while (shipsPlaced < numShips) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;

        if (grid[row][col] == '~') {
            grid[row][col] = 'S';
            shipsPlaced++;
        }
    }
}

bool isValidGuess(char grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    return row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE && grid[row][col] != 'X' && grid[row][col] != 'O';
}

bool checkHit(char grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    return grid[row][col] == 'S';
}

bool allShipsSunk(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                return false;
            }
        }
    }
    return true;
}
