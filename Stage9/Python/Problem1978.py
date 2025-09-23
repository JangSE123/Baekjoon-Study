def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def main():
    N = int(input())
    nums = list(map(int, input().split()))
    
    count = 0
    for num in nums:
        if is_prime(num):
            count += 1
    
    print(count)
    
if __name__ == "__main__":
    main()