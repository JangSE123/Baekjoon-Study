import sys
from collections import deque

input = sys.stdin.readline

MAX = 100001

def bfs(start, target, dist, prev):
    q = deque([start])
    dist[start] = 0

    while q:
        cur = q.popleft()

        if cur == target:
            return

        for nx in (cur - 1, cur + 1, cur * 2):
            if 0 <= nx < MAX and dist[nx] == -1:
                dist[nx] = dist[cur] + 1
                prev[nx] = cur
                q.append(nx)

def get_path(start, target, prev):
    path = []
    cur = target

    while cur != start:
        path.append(cur)
        cur = prev[cur]
    path.append(start)

    return path[::-1]

def main():
    N, K = map(int, input().split())

    dist = [-1] * MAX
    prev = [-1] * MAX

    bfs(N, K, dist, prev)

    print(dist[K])
    print(*get_path(N, K, prev))

if __name__ == "__main__":
    main()