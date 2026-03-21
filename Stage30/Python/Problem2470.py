import sys
input = sys.stdin.readline

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    
    arr.sort()
    
    left = 0
    right = N - 1
    
    ansL = arr[left]
    ansR = arr[right]
    min_val = float('inf')
    
    while left < right:
        sum_val = arr[left] + arr[right]
        
        if abs(sum_val) < min_val:
            min_val = abs(sum_val)
            ansL = arr[left]
            ansR = arr[right]
        
        if sum_val < 0:
            left += 1
        else:
            right -= 1
    
    print(ansL, ansR)

if __name__ == "__main__":
    main()