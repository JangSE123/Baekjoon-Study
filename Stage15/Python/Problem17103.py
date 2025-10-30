import sys
input = sys.stdin.readline
MAX = 1000000

def main():
    isPrime = [True] * (MAX + 1)
    isPrime[0] = isPrime[1] = False
    
    for i in range(2, int(MAX ** 0.5) + 1):
        if isPrime[i]:
            for j in range(i * i, MAX + 1, i):
                isPrime[j] = False
    
    T = int(input())
    
    for _ in range(T):
        N = int(input())
        count = 0
        
        if isPrime[2] and isPrime[N - 2]:
            count += 1
        
        for i in range(3, N // 2 + 1, 2):
            if isPrime[i] and isPrime[N - i]:
                count += 1
    
        print(count)            
    
if __name__ == "__main__":
    main()