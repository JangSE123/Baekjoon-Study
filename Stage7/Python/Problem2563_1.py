def main():
    covered = set()
    N = int(input())
    
    for _ in range(N):
        x, y = map(int, input().split())
        for i in range(x, x + 10):
            for j in range(y, y + 10):
                covered.add((i, j))
                
    print(len(covered))
    
if __name__ == "__main__":
    main()