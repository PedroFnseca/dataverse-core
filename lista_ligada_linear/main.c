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
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }
  list->size++;
}
void removeNode(LinkedList *list, int value) {
  Node *current = list->head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->data == value) {
        if (previous == NULL) {
            list->head = current->next;
            if (list->head == NULL) {
                list->tail = NULL;
            }
        } else {
            previous->next = current->next;
            if (current->next == NULL) {
                list->tail = previous;
            }
        }
        free(current);
        list->size--;
        return;
      }
    previous = current;
    current = current->next;
  }
}

void printLinkedList(LinkedList *list) {
  Node *current = list->head;
  if (current == NULL) {
    printf("Linked list is empty\n");
    return;
  }
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
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

  removeNode(&list, list.head->data); 
  printLinkedList(&list);

  return 0;
}