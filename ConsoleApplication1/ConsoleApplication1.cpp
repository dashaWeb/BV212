#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

const int N = 4;

void initialize_board(int tiles[][N]) {
    const int empty_tile = N * N;
    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tiles[i][j] = count++;
        }
    }
    tiles[N - 1][N - 1] = empty_tile;
}

void shuffle_board(int tiles[][N]) {
    srand(time_t(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x = rand() % N;
            int y = rand() % N;
            swap(tiles[i][j], tiles[x][y]);
        }
    }
}

void print_board(int tiles[][N]) {
    const int empty_tile = N * N;
    int moves = 0;
    system("cls");
    cout << "Moves: " << moves << endl;
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tiles[i][j] == empty_tile) {
                cout << "   ";
            }
            else {
                cout << tiles[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool is_solved(int tiles[][N]) {
    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tiles[i][j] != count++) {
                return false;
            }
        }
    }
    return true;
}

void move_up(int tiles[][N]) {
    const int empty_tile = N * N;
    int moves = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tiles[i][j] == empty_tile && i > 0) {
                swap(tiles[i][j], tiles[i - 1][j]);
                moves++;

            }
        }
    }
}

void move_down(int tiles[][N]) {
    const int empty_tile = N * N;
    int moves = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tiles[i][j] == empty_tile && i < N - 1) {
                swap(tiles[i][j], tiles[i + 1][j]);
                moves++;

            }
        }
    }
}

void move_left(int tiles[][N]) {
    const int empty_tile = N * N;
    int moves = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tiles[i][j] == empty_tile && j > 0) {
                swap(tiles[i][j], tiles[i][j - 1]);
                moves++;

            }
        }
    }
}

void move_right(int tiles[][N]) {
    const int empty_tile = N * N;
    int moves = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tiles[i][j] == empty_tile && j < N - 1) {
                swap(tiles[i][j], tiles[i][j + 1]);
                moves++;

            }
        }
    }
}

char* mystrchr(char* str, char s) {
    char* tmp = str;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (s == *tmp) {
            return tmp;
        }
        tmp++;
    }
}

int main()
{


   
}