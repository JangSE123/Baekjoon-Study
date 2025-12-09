import sys
input = sys.stdin.readline

board = []
blanks = []
row = [[False] * 10 for _ in range(9)]
col = [[False] * 10 for _ in range(9)]
box = [[False] * 10 for _ in range(9)]

def init():
    global board, blanks
    board = [list(map(int, input().split())) for _ in range(9)]

    for i in range(9):
        for j in range(9):
            num = board[i][j]
            if num == 0:
                blanks.append((i, j))
            else:
                row[i][num] = True
                col[j][num] = True
                box[(i // 3) * 3 + j // 3][num] = True

def dfs(idx):
    if idx == len(blanks):
        for r in board:
            print(*r)
        exit(0)

    i, j = blanks[idx]
    b = (i // 3) * 3 + j // 3

    for num in range(1, 10):
        if not row[i][num] and not col[j][num] and not box[b][num]:
            board[i][j] = num
            row[i][num] = col[j][num] = box[b][num] = True

            dfs(idx + 1)

            board[i][j] = 0
            row[i][num] = col[j][num] = box[b][num] = False

def main():
    init()
    dfs(0)

if __name__ == "__main__":
    main()