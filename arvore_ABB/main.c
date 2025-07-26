#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node;

typedef Node *Tree;

Tree createNode(int value) {
  Tree node = (Tree)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Erro de alocação de memória\n");
    exit(EXIT_FAILURE);
  }
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Tree insert(Tree root, int value) {
  if (root == NULL)
    return createNode(value);
  if (value < root->value)
    root->left = insert(root->left, value);
  else if (value > root->value)
    root->right = insert(root->right, value);
  return root;
}

void inorder(Tree root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
  }
}

void freeTree(Tree root) {
  if (root) {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}

int main() {
  Tree root = NULL;
  int values[] = {50, 30, 20, 40, 70, 60, 80};
  int size = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < size; i++) {
    root = insert(root, values[i]);
  }

  inorder(root);
  printf("\n");

  freeTree(root);
  return 0;
}
