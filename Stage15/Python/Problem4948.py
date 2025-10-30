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
    while (True):
        n = int(input())
        if (n == 0):
            break
        count = 0
        
        for i in range(n + 1, 2 * n + 1):
            if (isPrime(i)):
                count += 1
        print(count)
        
    
if __name__ == "__main__":
    main()