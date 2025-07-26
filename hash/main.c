#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct HashNode {
  int key;
  int value;
  struct HashNode *next;
} HashNode;

int hashFunction(int key, int tableSize) { return key % tableSize; }

HashNode *createNode(int key, int value) {
  HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insert(HashNode **table, int key, int value, int tableSize) {
  int index = hashFunction(key, tableSize);
  HashNode *newNode = createNode(key, value);

  if (table[index] == NULL) {
    table[index] = newNode;
  } else {
    HashNode *current = table[index];
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

int search(HashNode **table, int key, int tableSize) {
  int index = hashFunction(key, tableSize);
  HashNode *current = table[index];

  while (current != NULL) {
    if (current->key == key) {
      return current->value;
    }
    current = current->next;
  }

  return -1;
}

void freeTable(HashNode **table, int tableSize) {
  for (int i = 0; i < tableSize; i++) {
    HashNode *current = table[i];
    while (current != NULL) {
      HashNode *temp = current;
      current = current->next;
      free(temp);
    }
  }
}

void printTable(HashNode **table, int tableSize) {
  for (int i = 0; i < tableSize; i++) {
    HashNode *current = table[i];
    printf("Index %d: ", i);
    while (current != NULL) {
      printf("(%d, %d) -> ", current->key, current->value);
      current = current->next;
    }
    printf("NULL\n");
  }
}

void delete(HashNode **table, int key, int tableSize) {
  int index = hashFunction(key, tableSize);
  HashNode *current = table[index];
  HashNode *prev = NULL;

  while (current != NULL) {
    if (current->key == key) {
      if (prev == NULL) {
        table[index] = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

int fillTable(HashNode **table, int tableSize, int numElements) {
  for (int i = 0; i < numElements; i++) {
    int key = rand() % 100;
    int value = rand() % 1000;
    insert(table, key, value, tableSize);
  }
  return numElements;
}

int main() {
  srand(time(NULL));
  int tableSize = 10;
  HashNode **hashTable = (HashNode **)malloc(tableSize * sizeof(HashNode *));
  for (int i = 0; i < tableSize; i++) {
    hashTable[i] = NULL;
  }

  int numElements = fillTable(hashTable, tableSize, 20);
  printTable(hashTable, tableSize);

  int searchKey = rand() % 100;
  int value = search(hashTable, searchKey, tableSize);
  if (value != -1) {
    printf("Found key %d with value %d\n", searchKey, value);
  } else {
    printf("Key %d not found\n", searchKey);
  }

  delete(hashTable, searchKey, tableSize);
  printf("After deletion:\n");
  printTable(hashTable, tableSize);

  freeTable(hashTable, tableSize);
  free(hashTable);

  return 0;
}