#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10

typedef struct {
  int items[STACK_SIZE];
  int top;
} Stack;

void initStack(Stack *stack) {
  stack->top = -1;
}

void push(Stack *stack, int value) {
  if (stack->top < STACK_SIZE - 1) {
    stack->items[++stack->top] = value;
  } else {
    printf("Stack overflow\n");
  }
}

void pop(Stack *stack) {
  if (stack->top >= 0) {
    stack->top--;
  } else {
    printf("Stack underflow\n");
  }
}

void printStack(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = stack->top; i >= 0; i--) {
    printf("%d\n", stack->items[i]);
  }
}

void fillStackWithRandomValues(Stack *stack, int size) {
  for (int i = 0; i < size; i++) {
    push(stack, rand() % 100 + 1);
  }
}

int main() {
  Stack stack;
  initStack(&stack);
  fillStackWithRandomValues(&stack, 5);
  printStack(&stack);
  return 0;
}