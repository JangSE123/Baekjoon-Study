import sys
input = sys.stdin.readline

def quad(x, y, size):
    first = arr[x][y]

    for i in range(x, x + size):
        for j in range(y, y + size):
            if arr[i][j] != first:
                half = size // 2
                return "(" + \
                    quad(x, y, half) + \
                    quad(x, y + half, half) + \
                    quad(x + half, y, half) + \
                    quad(x + half, y + half, half) + ")"

    return first

def main():
    global arr
    N = int(input())
    arr = [list(input().strip()) for _ in range(N)]
    print(quad(0, 0, N))
    
if __name__ == "__main__":
    main()