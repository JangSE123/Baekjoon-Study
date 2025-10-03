def main():
    N = int(input())
    start = max(1, N - 9 * len(str(N)))
    result = 0
    
    for i in range(start, N):
        total = i + sum(map(int, str(i)))
        if total == N:
            result = i
            break
    
    print(result)

if __name__ == "__main__":
    main()