#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int c, int e) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;
    return temp;
}

void append(struct Node **head, int c, int e) {
    struct Node *newNode = createNode(c, e);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newNode;
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coeff, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%d", temp->coeff);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, c, e;
    struct Node *head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        append(&head, c, e);
    }

    display(head);
    return 0;
}
