import sys
input = sys.stdin.readline

def check(x, y, size):
    global white, blue
    color = paper[x][y]

    for i in range(x, x + size):
        for j in range(y, y + size):
            if paper[i][j] != color:
                half = size // 2
                check(x, y, half)
                check(x, y + half, half)
                check(x + half, y, half)
                check(x + half, y + half, half)
                return

    if color == 0:
        white += 1
    else:
        blue += 1


def main():
    global paper, white, blue

    N = int(input())
    paper = [list(map(int, input().split())) for _ in range(N)]

    white = 0
    blue = 0

    check(0, 0, N)

    print(white)
    print(blue)


if __name__ == "__main__":
    main()