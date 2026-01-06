import sys
input = sys.stdin.readline

def main():
    N, M, K = map(int, input().split())
    board = [""] + [input().strip() for _ in range(N)]

    psumW = [[0] * (M + 1) for _ in range(N + 1)]
    psumB = [[0] * (M + 1) for _ in range(N + 1)]

    for i in range(1, N + 1):
        for j in range(1, M + 1):
            is_white = (i + j) % 2 == 0

            w = 0 if board[i][j - 1] == ('W' if is_white else 'B') else 1
            b = 0 if board[i][j - 1] == ('B' if is_white else 'W') else 1

            psumW[i][j] = psumW[i - 1][j] + psumW[i][j - 1] \
                        - psumW[i - 1][j - 1] + w

            psumB[i][j] = psumB[i - 1][j] + psumB[i][j - 1] \
                        - psumB[i - 1][j - 1] + b

    ans = 10**9

    for i in range(K, N + 1):
        for j in range(K, M + 1):
            w = psumW[i][j] - psumW[i - K][j] \
            - psumW[i][j - K] + psumW[i - K][j - K]

            b = psumB[i][j] - psumB[i - K][j] \
            - psumB[i][j - K] + psumB[i - K][j - K]

            ans = min(ans, w, b)

    print(ans)
    
if __name__ == "__main__":
    main()