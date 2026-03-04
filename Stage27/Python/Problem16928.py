import sys
from collections import deque

input = sys.stdin.readline

def bfs(board):
    visited = [False] * 101
    queue = deque()
    queue.append((1, 0))
    visited[1] = True
    
    while queue:
        position, count = queue.popleft()
        
        if position == 100:
            return count
        
        for dice in range(1, 7):
            next_pos = position + dice
            
            if next_pos > 100:
                continue
            
            if board[next_pos] != 0:
                next_pos = board[next_pos]
                
            if not visited[next_pos]:
                visited[next_pos] = True
                queue.append((next_pos, count + 1))
    return -1

def main():
    N, M = map(int, input().split())
    board = [0] * 101

    for _ in range(N):
        a, b = map(int, input().split())
        board[a] = b

    for _ in range(M):
        a, b = map(int, input().split())
        board[a] = b

    print(bfs(board))
    
if __name__ == "__main__":
    main()