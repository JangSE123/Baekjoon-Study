import sys
input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    MOD = 1000000007
    
    fact = [1] * (N + 1)
    for i in range(1, N + 1):
        fact[i] = fact[i - 1] * i % MOD
        
    numerator = fact[N]
    denominator = fact[K] * fact[N - K] % MOD
    
    answer = numerator * pow(denominator, MOD - 2, MOD) % MOD
    print(answer)
    
if __name__ == "__main__":
    main()