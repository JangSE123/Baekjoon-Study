#include <stdio.h>
#include <string.h>

int graph[501][501];
int indegree[501];
int queue[501];
int result[501];

int main(void) {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        memset(graph, 0, sizeof(graph));
        memset(indegree, 0, sizeof(indegree));

        int rank[501];

        for (int i = 0; i < n; i++)
            scanf("%d", &rank[i]);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                graph[rank[i]][rank[j]] = 1;
                indegree[rank[j]]++;
            }

        int m;
        scanf("%d", &m);

        while (m--) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (graph[a][b]) {
                graph[a][b] = 0;
                graph[b][a] = 1;
                indegree[b]--;
                indegree[a]++;
            } 
            else {
                graph[b][a] = 0;
                graph[a][b] = 1;
                indegree[a]--;
                indegree[b]++;
            }
        }

        int front = 0, rear = 0;

        for (int i = 1; i <= n; i++)
            if (indegree[i] == 0)
                queue[rear++] = i;

        int certain = 1;
        int cycle = 0;
        int idx = 0;

        for (int i = 0; i < n; i++) {

            if (front == rear) {
                cycle = 1;
                break;
            }

            if (rear - front > 1)
                certain = 0;

            int now = queue[front++];
            result[idx++] = now;

            for (int j = 1; j <= n; j++) {
                if (graph[now][j]) {
                    indegree[j]--;
                    if (indegree[j] == 0)
                        queue[rear++] = j;
                }
            }
        }

        if (cycle)
            printf("IMPOSSIBLE\n");

        else if (!certain)
            printf("?\n");

        else {
            for (int i = 0; i < n; i++)
                printf("%d ", result[i]);
            printf("\n");
        }
    }
}