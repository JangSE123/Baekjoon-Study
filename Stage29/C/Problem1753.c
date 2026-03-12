#include <stdio.h>
#include <stdlib.h>

#define MAXV 20001
#define MAXE 300001
#define INF 2147483647

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* graph[MAXV];

typedef struct {
    int v, dist;
} Node;

Node heap[MAXE];
int hsize = 0;

int dist[MAXV];

void push(Node x) {
    heap[++hsize] = x;
    int i = hsize;

    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        Node tmp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = tmp;
        i /= 2;
    }
}

Node pop() {
    Node ret = heap[1];
    heap[1] = heap[hsize--];

    int i = 1;
    while (1) {
        int l = i * 2;
        int r = i * 2 + 1;
        int smallest = i;

        if (l <= hsize && heap[l].dist < heap[smallest].dist)
            smallest = l;

        if (r <= hsize && heap[r].dist < heap[smallest].dist)
            smallest = r;

        if (smallest == i) break;

        Node tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;

        i = smallest;
    }

    return ret;
}

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e -> to = v;
    e -> weight = w;
    e -> next = graph[u];
    graph[u] = e;
}

int main(void) {

    int V, E, K;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for (int i = 1; i <= V; i++) {
        graph[i] = NULL;
        dist[i] = INF;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    dist[K] = 0;
    push((Node){K, 0});

    while (hsize > 0) {

        Node cur = pop();
        int now = cur.v;
        int d = cur.dist;

        if (d > dist[now]) continue;

        Edge* e = graph[now];

        while (e) {
            int next = e -> to;
            int w = e -> weight;

            if (dist[next] > dist[now] + w) {
                dist[next] = dist[now] + w;
                push((Node){next, dist[next]});
            }

            e = e -> next;
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }

    return 0;
}