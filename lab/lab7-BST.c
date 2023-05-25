#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *Root, int value) {
    if (Root == NULL) {
        Node *newRoot = (Node *) malloc(sizeof(Node));
        newRoot->data = value;
        newRoot->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    } else {
        if (value >= Root->data) {
            Root->right = insert(Root->right, value);
        } else {
            Root->left = insert(Root->left, value);
        }
        return Root;
    }
}

void printTree(Node *Root) {
    if (Root != NULL) {
        printTree(Root->left);

        printf("%d ", Root->data);

        printTree(Root->right);
    }
}


int main() {
    Node *Root = NULL;
    srand(time(NULL));
    printf("Enter how many elements in the tree: ");
    int n, value;
    int check = scanf("%d", &n);
    if (check != 1) {
        printf("Incorrect input\n");
    }

    for (int i = 0; i < n; i++) {
        value = rand() % 1000;
        Root = insert(Root, value);
    }
    printf("Elements: ");
    printTree(Root);
    return 0;
}