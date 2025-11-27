memo = {}

def fibonacci(n):
    if n <= 1:
        return n
    if n in memo:
        return memo[n]
    memo[n] = fibonacci(n-1) + fibonacci(n-2)
    return memo[n]

def main():
    N = int(input())
    
    print(fibonacci(N))
    
if __name__ == "__main__":
    main()