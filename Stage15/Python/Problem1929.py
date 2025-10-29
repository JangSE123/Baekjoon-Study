import math

def isPrime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def main():
    M, N = map(int, input().split())
    
    for i in range(M, N + 1):
        if isPrime(i):
            print(i)

if __name__ == "__main__":
    main()