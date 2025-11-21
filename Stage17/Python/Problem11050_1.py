import math

def main():
    N, K = map(int, input().split())
    result = 1
    
    for i in range(1, K + 1):
        result = result * (N - i + 1) // i
    
    print(result)

if __name__ == "__main__":
    main()