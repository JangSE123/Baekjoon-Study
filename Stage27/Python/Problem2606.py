import sys
from collections import deque

input = sys.stdin.readline

def bfs(start, graph, visited):
    queue = deque([start])
    visited[start] = True
    count = 0
    
    while queue:
        node = queue.popleft()
        
        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                queue.append(next_node)
                count += 1
    
    return count

def main():
    com = int(input())
    line = int(input())
    
    graph = [[] for _ in range(com + 1)]
    visited = [False] * (com + 1)
    
    for _ in range(line):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    
    print(bfs(1, graph, visited))

if __name__ == "__main__":
    main()