import sys
input = sys.stdin.readline

def main():
    K, N = map(int, input().split())
    arr = []
    
    max_len = 0
    for _ in range(K):
        x = int(input())
        arr.append(x)
        if x > max_len:
            max_len = x
        
    left = 1
    right = max_len
    answer = 0
    
    while left <= right:
        mid = (left + right) // 2
        
        count = 0
        for x in arr:
            count += x // mid
        
        if count >= N:
            answer = mid
            left = mid + 1
        else:
            right = mid - 1
        
    print(answer)
    
if __name__ == "__main__":
    main()