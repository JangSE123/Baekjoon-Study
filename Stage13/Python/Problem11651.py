import sys

def main():
    input = sys.stdin.readline
    
    N = int(input())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    
    points.sort(key = lambda x: (x[1], x[0]))
    
    for x, y in points:
        print(x, y)
    
if __name__ == "__main__":
    main()