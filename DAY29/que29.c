#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    struct Node* temp = head;
    int count = 1;

    while (temp->next) {
        temp = temp->next;
        count++;
    }

    k = k % count;
    if (k == 0)
        return head;

    temp->next = head;

    int steps = count - k;
    temp = head;

    while (--steps)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k, x;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}
