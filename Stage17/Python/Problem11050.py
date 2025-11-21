import math

def main():
    N, K = map(int, input().split())
    result = math.factorial(N) // (math.factorial(K) * math.factorial(N - K))
    print(result)

if __name__ == "__main__":
    main()