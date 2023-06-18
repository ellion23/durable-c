#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int coef;
    int degree;
    struct Node *next;
} Node;

typedef Node *PNode;

PNode Head = NULL;

PNode CreateNode(int coef, int degree) {
    PNode NewNode = (PNode) malloc(sizeof(Node));
    NewNode->coef = coef;
    NewNode->degree = degree;
    NewNode->next = NULL;
    return NewNode;
}

void AddFirst(PNode *Head, PNode NewNode) {
    NewNode->next = *Head;
    *Head = NewNode;
}

void show(PNode Head) {
    if (Head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("P(x) = %dx^%d", Head->coef, Head->degree);
    Head = Head->next;
    while (Head) {
        if (Head->next) {
            if (Head->coef > 0)
                printf("+%dx^%d", Head->coef, Head->degree);
            else
                printf("%dx^%d", Head->coef, Head->degree);
        } else {
            if (Head->coef > 0)
                printf("%+dx^%d\n", Head->coef, Head->degree);
            else
                printf("%dx^%d\n", Head->coef, Head->degree);
        }
        Head = Head->next;
    }
}

PNode DIF(PNode q) {
    int new_coef = q->coef * q->degree;
    int new_degree = q->degree - 1;
    PNode p = (PNode) malloc(sizeof(Node));
    p->coef = new_coef;
    p->degree = new_degree;
    p->next = q;
    return p;
}

PNode read_lifo(char *name, PNode *Head) {
    int coef, degree, i;
    FILE *f = fopen(name, "r");
    if (f == NULL) {
        printf("Error.\n");
        system("pause");
        exit(0);
    }
    int kol;
    printf("Enter the number of the x in the polinom:\n");
    scanf("%d", &kol);
    PNode lifo;
    for (i = 0; i < kol; i++) {
        fscanf(f, "%d", &coef);
        fscanf(f, "%d", &degree);
        if (coef != 0) {
            lifo = CreateNode(coef, degree);
            AddFirst(Head, lifo);
        }
    }
    fclose(f);
    return lifo;
}

void DeleteNode(PNode *Head, PNode OldNode) {
    PNode q = *Head;
    if (*Head == OldNode)
        *Head = OldNode->next;
    else {
        while (q && q->next != OldNode)
            q = q->next;
        if (q == NULL) return;
        q->next = OldNode->next;
    }
    free(OldNode);
}

int main() {

    PNode q = read_lifo("../lab/a.txt", &Head);
    show(q);
    PNode p;
    PNode p1 = q;
    while (q != NULL) {
        p = DIF(q);
        q = q->next;
    }
    show(p);
    DeleteNode(&Head, p);
    DeleteNode(&Head, p1);
    return 0;
}

