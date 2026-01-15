import sys
input = sys.stdin.readline

minus = 0
zero = 0
plus = 0

def countPaper(x, y, size):
    global minus, zero, plus
    
    first = paper[x][y]
    same = True
    
    for i in range(x, x + size):
        for j in range(y, y + size):
            if paper[i][j] != first:
                same = False
                break
        if not same:
            break
    
    if same:
        if first == -1:
            minus += 1
        elif first == 0:
            zero += 1
        else:
            plus += 1
        return
    
    newSize = size // 3
    for i in range(3):
        for j in range(3):
            countPaper(x + i * newSize, y + j * newSize, newSize)

def main():
    global paper
    
    N = int(input())
    paper = [list(map(int, input().split())) for _ in range(N)]
    
    countPaper(0, 0, N)
    
    print(minus)
    print(zero)
    print(plus)
    
if __name__ == "__main__":
    main()