import sys

def main():
    input = sys.stdin.readline

    N, M1 = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(N)]

    M2, K = map(int, input().split())
    B = [list(map(int, input().split())) for _ in range(M2)]

    for i in range(N):
        for j in range(K):
            s = 0
            for t in range(M1):
                s += A[i][t] * B[t][j]
            print(s, end=' ')
        print()

if __name__ == "__main__":
    main()