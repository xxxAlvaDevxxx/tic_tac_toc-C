#include <stdio.h>

#define SIZE 3

// Estructura para representar el tablero del juego
struct Tablero {
    char casillas[SIZE][SIZE];
};

// Función para inicializar el tablero del juego
void inicializarTablero(struct Tablero* tablero) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            tablero->casillas[i][j] = ' ';
        }
    }
}

// Función para imprimir el tablero del juego
void imprimirTablero(struct Tablero* tablero) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf(" %c ", tablero->casillas[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
}

// Función para verificar si hay un ganador
char verificarGanador(struct Tablero* tablero) {
    int i;

    // Verificar filas
    for (i = 0; i < SIZE; i++) {
        if (tablero->casillas[i][0] != ' ' &&
            tablero->casillas[i][0] == tablero->casillas[i][1] &&
            tablero->casillas[i][0] == tablero->casillas[i][2]) {
            return tablero->casillas[i][0];
        }
    }

    // Verificar columnas
    for (i = 0; i < SIZE; i++) {
        if (tablero->casillas[0][i] != ' ' &&
            tablero->casillas[0][i] == tablero->casillas[1][i] &&
            tablero->casillas[0][i] == tablero->casillas[2][i]) {
            return tablero->casillas[0][i];
        }
    }

    // Verificar diagonales
    if (tablero->casillas[0][0] != ' ' &&
        tablero->casillas[0][0] == tablero->casillas[1][1] &&
        tablero->casillas[0][0] == tablero->casillas[2][2]) {
        return tablero->casillas[0][0];
    }

    if (tablero->casillas[0][2] != ' ' &&
        tablero->casillas[0][2] == tablero->casillas[1][1] &&
        tablero->casillas[0][2] == tablero->casillas[2][0]) {
        return tablero->casillas[0][2];
    }

    return ' '; // No hay ganador
}

// Función para realizar un movimiento en el tablero
void realizarMovimiento(struct Tablero* tablero, int fila, int columna, char jugador) {
    tablero->casillas[fila][columna] = jugador;
}

int main() {
    struct Tablero tablero;
    char jugadorActual = 'X';
    int fila, columna;

    inicializarTablero(&tablero);

    while (1) {
        printf("Turno del jugador %c\n", jugadorActual);
        printf("Ingrese la fila (0-2): ");
        scanf("%d", &fila);
        printf("Ingrese la columna (0-2): ");
        scanf("%d", &columna);

        if (fila < 0 || fila >= SIZE || columna < 0 || columna >= SIZE) {
            printf("Movimiento inválido. Inténtalo de nuevo.\n");
            continue;
        }

        if (tablero.casillas[fila][columna] != ' ') {
            printf("Esa casilla ya está ocupada. Inténtalo de nuevo.\n");
            continue;
        }

        realizarMovimiento(&tablero, fila, columna, jugadorActual);
        imprimirTablero(&tablero);

        char ganador = verificarGanador(&tablero);
        if (ganador != ' ') {
            printf("¡El jugador %c ha ganado!\n", ganador);
            break;
        }

        // Cambiar al siguiente jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    return 0;
}
