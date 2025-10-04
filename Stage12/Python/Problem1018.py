def main():
    N, M = map(int, input().split())
    board = [input().strip() for _ in range(N)]

    def repaint_count(x, y):
        cnt1, cnt2 = 0, 0
        for i in range(8):
            for j in range(8):
                current = board[x+i][y+j]
                if (i + j) % 2 == 0:
                    if current != 'W':
                        cnt1 += 1
                    if current != 'B':
                        cnt2 += 1
                else:
                    if current != 'B':
                        cnt1 += 1
                    if current != 'W':
                        cnt2 += 1
        return min(cnt1, cnt2)

    result = float('inf')
    for i in range(N - 7):
        for j in range(M - 7):
            result = min(result, repaint_count(i, j))

    print(result)

if __name__ == "__main__":
    main()