from collections import deque
import sys
input = sys.stdin.readline

def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    dq = deque()

    for i in range(N - 1, -1, -1):
        if A[i] == 0:
            dq.append(B[i])

    M = int(input())
    C = list(map(int, input().split()))

    result = []
    for x in C:
        dq.append(x)
        result.append(dq.popleft())

    print(*result)

if __name__ == "__main__":
    main()