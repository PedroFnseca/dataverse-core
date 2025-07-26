#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUEUE_SIZE 10

typedef struct {
  int items[QUEUE_SIZE];
  int front;
  int rear;
} Queue;

void initQueue(Queue *queue) {
  queue->front = 0;
  queue->rear = -1;
}

int isFull(Queue *queue) {
  return queue->rear == QUEUE_SIZE - 1;
}

int isEmpty(Queue *queue) {
  return queue->front > queue->rear;
}

void enqueue(Queue *queue, int value) {
  if (!isFull(queue)) {
    queue->items[++queue->rear] = value;
  } else {
    printf("Queue overflow\n");
  }
}

void dequeue(Queue *queue) {
  if (!isEmpty(queue)) {
    queue->front++;
  } else {
    printf("Queue underflow\n");
  }
}

void printQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d\n", queue->items[i]);
  }
}

void fillQueueWithRandomValues(Queue *queue, int size) {
  for (int i = 0; i < size; i++) {
    enqueue(queue, rand() % 100 + 1);
  }
}

int main() {
  Queue queue;
  initQueue(&queue);
  fillQueueWithRandomValues(&queue, 5);
  printQueue(&queue);
  return 0;
}