import sys

input = sys.stdin.readline

def main():
    N = int(input())
    
    is_prime = [True] * (N + 1)
    if N >= 0: is_prime[0] = False
    if N >= 1: is_prime[1] = False
    
    for i in range(2, int(N**0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, N + 1, i):
                is_prime[j] = False
    
    primes = [i for i in range(2, N + 1) if is_prime[i]]
    
    left, right = 0, 0
    sum_val = 0
    count = 0
    
    while True:
        if sum_val >= N:
            if sum_val == N:
                count += 1
            sum_val -= primes[left]
            left += 1
        else:
            if right == len(primes):
                break
            sum_val += primes[right]
            right += 1
    
    print(count)

if __name__ == "__main__":
    main()