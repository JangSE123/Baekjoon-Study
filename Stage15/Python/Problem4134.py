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
    T = int(input())
    
    for _ in range(T):
        n = int(input())
        
        while not isPrime(n):
            n += 1
        print(n)
    

if __name__ == "__main__":
    main()