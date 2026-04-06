#include <stdio.h>

int visited[100];

void dfs(int v, int n, int adj[100][100]) {
    printf("%d ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i, n, adj);
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

    dfs(s, n, adj);

    return 0;
}
