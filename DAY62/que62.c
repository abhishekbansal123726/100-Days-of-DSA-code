#include <stdio.h>

int queue[100], front=-1, rear=-1;

void enqueue(int x) {
    if(rear==99) return;
    if(front==-1) front=0;
    queue[++rear]=x;
}

void dequeue() {
    if(front==-1 || front>rear) return;
    front++;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    for(int i=front;i<=rear;i++)
        printf("%d ", queue[i]);
}
