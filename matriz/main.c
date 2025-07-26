#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 3
#define CHILD_SIZE 3

void fillMatrixWithRandomValues(int matrix[MATRIX_SIZE][CHILD_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < CHILD_SIZE; j++) {
      matrix[i][j] = rand() % 100 + 1; // valores entre 1 e 100
    }
  }
}

void printMatrix(int matrix[MATRIX_SIZE][CHILD_SIZE], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < CHILD_SIZE; j++) {
      if (j == CHILD_SIZE - 1) {
        printf("%d\n", matrix[i][j]);
      } else {
        printf("%d - ", matrix[i][j]);
      }
    }
  }
  printf("\n");
}

void fillDynamicMatrixWithRandomValues(int *matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < CHILD_SIZE; j++) {
      matrix[i * CHILD_SIZE + j] = rand() % 100 + 1; // valores entre 1 e 100
    }
  }
}

void printDynamicMatrix(int *matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < CHILD_SIZE; j++) {
      if (j == CHILD_SIZE - 1) {
        printf("%d\n", matrix[i * CHILD_SIZE + j]);
      } else {
        printf("%d - ", matrix[i * CHILD_SIZE + j]);
      }
    }
  }
  printf("\n");
}

int main() {
  int matriz[MATRIX_SIZE][CHILD_SIZE];
  srand(time(NULL));

  // Matriz estática
  fillMatrixWithRandomValues(matriz, MATRIX_SIZE);
  printMatrix(matriz, MATRIX_SIZE);

  // Matriz dinâmica
  int *dynamicMatrix = malloc(sizeof(int) * MATRIX_SIZE * CHILD_SIZE);
  fillDynamicMatrixWithRandomValues(dynamicMatrix, MATRIX_SIZE);
  printDynamicMatrix(dynamicMatrix, MATRIX_SIZE);
  free(dynamicMatrix);

  return 0;
}