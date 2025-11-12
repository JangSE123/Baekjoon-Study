import sys
from collections import deque
input = sys.stdin.readline

def main():
    N = int(input())
    q = deque()
    
    for _ in range(N):
        command = input().split()
        
        if command[0] == "push":
            q.append(command[1])
        elif command[0] == "pop":
            print(q.popleft() if q else -1)
        elif command[0] == "size":
            print(len(q))
        elif command[0] == "empty":
            print(0 if q else 1)
        elif command[0] == "front":
            print(q[0] if q else -1)
        elif command[0] == "back":
            print(q[-1] if q else -1)

if __name__ == "__main__":
    main()