#include <stdio.h>
#include <limits.h>

#define MAX 100001

int dist[MAX];
int deque[MAX * 2];
int front = MAX;
int back = MAX;

void push_front(int x) {
    deque[--front] = x;
}

void push_back(int x) {
    deque[back++] = x;
}

int pop_front() {
    return deque[front++];
}

int empty() {
    return front == back;
}

int bfs(int start, int target) {

    for (int i = 0; i < MAX; i++)
        dist[i] = INT_MAX;

    push_front(start);
    dist[start] = 0;

    while (!empty()) {

        int cur = pop_front();

        if (cur == target)
            return dist[cur];

        int next;

        next = cur * 2;
        if (next < MAX && dist[next] > dist[cur]) {
            dist[next] = dist[cur];
            push_front(next);
        }

        next = cur - 1;
        if (next >= 0 && dist[next] > dist[cur] + 1) {
            dist[next] = dist[cur] + 1;
            push_back(next);
        }

        next = cur + 1;
        if (next < MAX && dist[next] > dist[cur] + 1) {
            dist[next] = dist[cur] + 1;
            push_back(next);
        }
    }

    return -1;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    printf("%d\n", bfs(N, K));

    return 0;
}