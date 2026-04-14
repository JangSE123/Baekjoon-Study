#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

int queue[MAX];
int front, rear;

bool visited[MAX];
int parent[MAX];
char command[MAX];

void bfs(int A, int B) {
    front = rear = 0;

    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }

    queue[rear++] = A;
    visited[A] = true;

    while (front < rear) {
        int now = queue[front++];

        if (now == B) break;

        int d = (now * 2) % 10000;
        if (!visited[d]) {
            visited[d] = true;
            parent[d] = now;
            command[d] = 'D';
            queue[rear++] = d;
        }

        int s = (now == 0) ? 9999 : now - 1;
        if (!visited[s]) {
            visited[s] = true;
            parent[s] = now;
            command[s] = 'S';
            queue[rear++] = s;
        }

        int l = (now % 1000) * 10 + (now / 1000);
        if (!visited[l]) {
            visited[l] = true;
            parent[l] = now;
            command[l] = 'L';
            queue[rear++] = l;
        }

        int r = (now % 10) * 1000 + (now / 10);
        if (!visited[r]) {
            visited[r] = true;
            parent[r] = now;
            command[r] = 'R';
            queue[rear++] = r;
        }
    }

    char result[MAX];
    int idx = 0;

    int cur = B;
    while (cur != A) {
        result[idx++] = command[cur];
        cur = parent[cur];
    }

    for(int i = idx - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int A, B;
        scanf("%d %d", &A, &B);

        bfs(A, B);
    }
    
    return 0;
}