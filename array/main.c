#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void fillArrayWithRandomValues(int array[], int size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100 + 1; // valores entre 1 e 100
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d\n", array[i]);
    } else {
      printf("%d - ", array[i]);
    }
  }
}

void fillDynamicArrayWithRandomValues(int *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100 + 1; // valores entre 1 e 100
  }
}

void printDynamicArray(int *array, int size) {
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d\n", array[i]);
    } else {
      printf("%d - ", array[i]);
    }
  }
}

int main() {
  srand(time(NULL));

  // Array estático
  int staticArray[ARRAY_SIZE];
  fillArrayWithRandomValues(staticArray, ARRAY_SIZE);
  printArray(staticArray, ARRAY_SIZE);

  // Array dinâmico
  int *dynamicArray = malloc(sizeof(int) * ARRAY_SIZE);
  fillDynamicArrayWithRandomValues(dynamicArray, ARRAY_SIZE);
  printDynamicArray(dynamicArray, ARRAY_SIZE);
  free(dynamicArray);

  return 0;
}
