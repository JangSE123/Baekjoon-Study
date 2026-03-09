#include <stdio.h>
#include <stdlib.h>

#define MAX 32001

int N, M;

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* graph[MAX];
int indegree[MAX];

int queue[MAX];
int front = 0; 
int rear = 0;

void push(int x) {
    queue[rear++] = x;
}

int pop() {
    return queue[front++];
}

int empty() {
    return front == rear;
}

void addEdge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->v = v;
    node->next = graph[u];
    graph[u] = node;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);

        addEdge(A, B);
        indegree[B]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            push(i);
        }
    }

    while (!empty()) {
        int cur = pop();
        printf("%d ", cur);

        Node* temp = graph[cur];
        while (temp) {
            int next = temp->v;
            indegree[next]--;

            if (indegree[next] == 0) {
                push(next);
            }

            temp = temp->next;
        }
    }

    return 0;
}