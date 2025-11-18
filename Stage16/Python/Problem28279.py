from collections import deque
import sys
input = sys.stdin.readline

def main():
    N = int(input())
    dq = deque()
    
    for _ in range(N):
        cmd = (input().split())
        
        if cmd[0] == '1':
            dq.appendleft(int(cmd[1]))
        elif cmd[0] == '2':
            dq.append(int(cmd[1]))
        elif cmd[0] == '3':
            print(dq.popleft() if dq else -1)
        elif cmd[0] == '4':
            print(dq.pop() if dq else -1)
        elif cmd[0] == '5':
            print(len(dq))
        elif cmd[0] == '6':
            print(0 if dq else 1)
        elif cmd[0] == '7':
            print(dq[0] if dq else -1)
        elif cmd[0] == '8':
            print(dq[-1] if dq else -1)
    
if __name__ == "__main__":
    main()