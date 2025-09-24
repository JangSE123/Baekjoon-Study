def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def main():
    M = int(input())
    N = int(input())
    
    sum = 0
    min = 0
    
    for i in range(M, N + 1):
        if is_prime(i):
            sum += i
            if min == 0:
                min = i
    if sum == 0:
        print(-1)
    else:
        print(sum)
        print(min)
        
if __name__ == "__main__":
    main()