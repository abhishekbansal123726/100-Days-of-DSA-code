#include <stdio.h>

#define MAX 100

int main()
{
    int q[MAX];
    int front = 0, rear = -1, size = 0;
    int n, m, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        rear = (rear + 1) % MAX;
        q[rear] = x;
        size++;
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        if(size > 0)
        {
            front = (front + 1) % MAX;
            size--;
        }
    }

    for(int i = 0; i < size; i++)
    {
        printf("%d ", q[(front + i) % MAX]);
    }

    return 0;
}
