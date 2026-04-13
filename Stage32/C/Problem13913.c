#include <stdio.h>

#define MAX 100001

int dist[MAX];
int prev[MAX];
int queue[MAX];

void bfs(int start, int target) {
    for (int i = 0; i < MAX; i++) dist[i] = -1;

    int front = 0, rear = 0;
    queue[rear++] = start;
    dist[start] = 0;

    while (front < rear) {
        int cur = queue[front++];

        if (cur == target) return;

        int next[3] = {cur - 1, cur + 1, cur * 2};

        for (int i = 0; i < 3; i++) {
            int nx = next[i];

            if (nx >= 0 && nx < MAX && dist[nx] == -1) {
                dist[nx] = dist[cur] + 1;
                prev[nx] = cur;
                queue[rear++] = nx;
            }
        }
    }
}

void printPath(int start, int target) {
    int path[MAX];
    int idx = 0;
    int cur = target;

    while (cur != start) {
        path[idx++] = cur;
        cur = prev[cur];
    }
    path[idx++] = start;

    for (int i = idx - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    bfs(N, K);

    printf("%d\n", dist[K]);
    printPath(N, K);

    return 0;
}