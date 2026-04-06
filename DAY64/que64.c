#include <stdio.h>

int visited[100];
int queue[100];

void bfs(int n, int adj[100][100], int s) {
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, s;
    int adj[100][100];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    bfs(n, adj, s);

    return 0;
}
