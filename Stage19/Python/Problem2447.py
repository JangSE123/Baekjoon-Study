import sys
input = sys.stdin.readline

def draw(board, x, y, size):
    if size == 1:
        return

    newSize = size // 3

    for i in range(x + newSize, x + 2 * newSize):
        for j in range(y + newSize, y + 2 * newSize):
            board[i][j] = ' '

    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1: 
                continue
            draw(board, x + i * newSize, y + j * newSize, newSize)

def main():
    N = int(input())
    board = [['*'] * N for _ in range(N)]

    draw(board, 0, 0, N)

    print("\n".join("".join(row) for row in board))

if __name__ == "__main__":
    main()