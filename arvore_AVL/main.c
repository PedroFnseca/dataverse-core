#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
  int key;
  struct AVLNode *left;
  struct AVLNode *right;
  int height;
} AVLNode;

AVLNode *createNode(int key) {
  AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1;
  return newNode;
}

int height(AVLNode *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

int maxValue(int a, int b) { return (a > b) ? a : b; }

int getBalance(AVLNode *node) {
  if (node == NULL)
    return 0;
  return height(node->left) - height(node->right);
}

AVLNode *rightRotate(AVLNode *y) {
  AVLNode *x = y->left;
  AVLNode *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = maxValue(height(y->left), height(y->right)) + 1;
  x->height = maxValue(height(x->left), height(x->right)) + 1;

  return x;
}

AVLNode *leftRotate(AVLNode *x) {
  AVLNode *y = x->right;
  AVLNode *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = maxValue(height(x->left), height(x->right)) + 1;
  y->height = maxValue(height(y->left), height(y->right)) + 1;

  return y;
}

AVLNode *insert(AVLNode *node, int key) {
  if (node == NULL)
    return createNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  else
    return node;

  node->height = 1 + maxValue(height(node->left), height(node->right));

  int balance = getBalance(node);

  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

void preOrder(AVLNode *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main() {
  AVLNode *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  printf("Pre-order traversal of the AVL tree is:\n");
  preOrder(root);

  return 0;
}