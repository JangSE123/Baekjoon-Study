import sys

input = sys.stdin.readline

def main():
    T = int(input())
    
    for _ in range(T):
        K = int(input())
        files = list(map(int, input().split()))
        
        prefix = [0] * (K + 1)
        for i in range(K):
            prefix[i+1] = prefix[i] + files[i]
        
        dp = [[0] * K for _ in range(K)]
        opt = [[0] * K for _ in range(K)]
        
        for i in range(K):
            opt[i][i] = i
        
        for length in range(2, K + 1):
            for i in range(K - length + 1):
                j = i + length - 1
                dp[i][j] = int(1e9)
                
                start = opt[i][j-1]
                end = opt[i+1][j]
                
                if end > j - 1:
                    end = j - 1
                
                for k in range(start, end + 1):
                    cost = dp[i][k] + dp[k+1][j] + (prefix[j+1] - prefix[i])
                    
                    if cost < dp[i][j]:
                        dp[i][j] = cost
                        opt[i][j] = k
        
        print(dp[0][K-1])

if __name__ == "__main__":
    main()