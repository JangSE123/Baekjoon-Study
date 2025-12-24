def main():
    n = int(input())
    wire = []
    
    for _ in range(n):
        a, b = map(int, input().split())
        wire.append((a, b))
        
    wire.sort()
    dp = [1] * n
    
    for i in range(n):
        for j in range(i):
            if wire[j][1] < wire[i][1]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    print(n - max(dp))
    
if __name__ == "__main__":
    main()