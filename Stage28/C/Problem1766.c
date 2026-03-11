#include <stdio.h>
#include <stdlib.h>

#define MAX 32001
#define MAXM 100001

int N, M;
int indegree[MAX];

int heap[MAX];
int hsize = 0;

int graph[MAXM][2];
int gsize[MAX];

void push(int x) {
    heap[++hsize] = x;
    
    int i = hsize;
    while (i > 1 && heap[i] < heap[i / 2]) {
        int tmp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = tmp;
        i /= 2;
    }
}

int pop() {
    int ret = heap[1];
    heap[1] = heap[hsize--];
    
    int i = 1;
    while(1) {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallest = i;

        if (left <= hsize && heap[left] < heap[smallest])
            smallest = left;
        if (right <= hsize && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        int tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;

        i = smallest;
    }

    return ret;
}

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);

        graph[i][0] = A;
        graph[i][1] = B;
        gsize[A]++; 
        indegree[B]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) push(i);
    }

    while (hsize) {
        int now = pop();
        printf("%d ",now);

        for (int i = 0; i < M; i++) {
            if (graph[i][0] == now) {
                int next = graph[i][1];
                indegree[next]--;

                if (indegree[next]==0)
                    push(next);
            }
        }
    }
}