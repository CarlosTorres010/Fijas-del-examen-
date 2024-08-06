#include <iostream>
using namespace std;

const int N = 3; // Tamaño de la matriz

void imprimirMatriz(double matriz[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

bool inversaMatriz(double matriz[N][N], double inversa[N][N]) {
    double aumentado[N][2 * N];
    
    // Inicializar la matriz aumentada [A | I]
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            aumentado[i][j] = matriz[i][j];
            aumentado[i][j + N] = (i == j) ? 1 : 0; 
        }
    }

    // Aplicar el método de Gauss-Jordan
    for (int i = 0; i < N; ++i) {
        double pivote = aumentado[i][i];
        if (pivote == 0) {
            // Usar cout para mensajes de error
            cout << "La matriz no es invertible." << endl;
            return false;
        }

        // Normalizar la fila del pivote
        for (int j = 0; j < 2 * N; ++j) {
            aumentado[i][j] /= pivote;
        }

        // Hacer ceros en la columna del pivote en otras filas
        for (int k = 0; k < N; ++k) {
            if (k != i) {
                double factor = aumentado[k][i];
                for (int j = 0; j < 2 * N; ++j) {
                    aumentado[k][j] -= factor * aumentado[i][j];
                }
            }
        }
    }

    // Extraer la matriz inversa
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inversa[i][j] = aumentado[i][j + N];
        }
    }

    return true;
}

int main() {
    double matriz[N][N] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    double inversa[N][N];

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    if (inversaMatriz(matriz, inversa)) {
        cout << "\nMatriz inversa:" << endl;
        imprimirMatriz(inversa);
    } else {
        cout << "No se pudo calcular la matriz inversa." << endl;
    }

    return 0;
}


