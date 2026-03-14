import sys
from collections import deque

input = sys.stdin.readline
MAX = 100001

def bfs(start, target):
    dist = [float('inf')] * MAX
    dq = deque()

    dq.append(start)
    dist[start] = 0

    while dq:
        cur = dq.popleft()

        if cur == target:
            return dist[cur]

        next_pos = cur * 2
        if next_pos < MAX and dist[next_pos] > dist[cur]:
            dist[next_pos] = dist[cur]
            dq.appendleft(next_pos)

        next_pos = cur - 1
        if next_pos >= 0 and dist[next_pos] > dist[cur] + 1:
            dist[next_pos] = dist[cur] + 1
            dq.append(next_pos)

        next_pos = cur + 1
        if next_pos < MAX and dist[next_pos] > dist[cur] + 1:
            dist[next_pos] = dist[cur] + 1
            dq.append(next_pos)

def main():
    N, K = map(int, input().split())
    print(bfs(N, K))

if __name__ == "__main__":
    main()