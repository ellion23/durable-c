#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *Root, int key) {
    if (Root == NULL) {
        Node *newRoot = (Node *) malloc(sizeof(Node));
        newRoot->data = key;
        newRoot->left = NULL;
        newRoot->right = NULL;
        return newRoot;
    } else {
        if (key >= Root->data) {
            Root->right = insert(Root->right, key);
        } else {
            Root->left = insert(Root->left, key);
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
    int n, key;
    int check = scanf("%d", &n);
    if (check != 1) {
        printf("Incorrect input\n");
    }

    for (int i = 0; i < n; i++) {
        key = rand() % 1000;
        Root = insert(Root, key);
    }
    printf("Recursive output: ");
    printTree(Root);
//    printf("Non-recursive output: ");

    return 0;
}