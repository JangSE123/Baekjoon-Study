import sys
import heapq

input = sys.stdin.readline

def main():
    n = int(input())
    m = int(input())
    
    graph = [[] for _ in range(n + 1)]
    
    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a].append((b, c))
    
    start, end = map(int, input().split())
    
    INF = int(1e9)
    dist = [INF] * (n + 1)
    prev = [0] * (n + 1)
    
    pq = []
    dist[start] = 0
    heapq.heappush(pq, (0, start))
    
    while pq:
        cost, now = heapq.heappop(pq)
        
        if cost > dist[now]:
            continue
        
        for next_node, next_cost in graph[now]:
            new_cost = cost + next_cost
            if dist[next_node] > new_cost:
                dist[next_node] = new_cost
                prev[next_node] = now
                heapq.heappush(pq, (new_cost, next_node))
    
    print(dist[end])
    
    path = []
    cur = end
    while cur:
        path.append(cur)
        cur = prev[cur]
    
    print(len(path))
    print(*reversed(path))

if __name__ == "__main__":
    main()