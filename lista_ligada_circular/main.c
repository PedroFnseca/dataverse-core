#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINKED_LIST_SIZE 10

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

void initLinkedList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void addNode(LinkedList *list, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
    newNode->next = newNode; // aponta para si mesmo (1 elemento)
  } else {
    newNode->next = list->head;
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++;
}

void removeNode(LinkedList *list, int value) {
  if (list->head == NULL) return;

  Node *current = list->head;
  Node *previous = list->tail;
  int traversed = 0;

  do {
    if (current->data == value) {
      if (current == list->head) {
        if (list->head == list->tail) {
          free(current);
          list->head = NULL;
          list->tail = NULL;
        } else {
          list->head = current->next;
          list->tail->next = list->head;
          free(current);
        }
      } else {
        previous->next = current->next;
        if (current == list->tail) {
          list->tail = previous;
        }
        free(current);
      }

      list->size--;
      return;
    }

    previous = current;
    current = current->next;
    traversed++;
  } while (current != list->head && traversed <= list->size);
}

void printLinkedList(LinkedList *list) {
  if (list->head == NULL) {
    printf("Lista ligada circular está vazia\n");
    return;
  }

  Node *current = list->head;
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != list->head);
  printf("\n");
}

void fillLinkedListWithRandomValues(LinkedList *list, int size) {
  for (int i = 0; i < size; i++) {
    addNode(list, rand() % 100 + 1);
  }
}

int main() {
  srand(time(NULL));

  LinkedList list;
  initLinkedList(&list);
  fillLinkedListWithRandomValues(&list, LINKED_LIST_SIZE);
  printLinkedList(&list);

  if (list.head != NULL)
    removeNode(&list, list.head->data);

  printLinkedList(&list);

  return 0;
}
