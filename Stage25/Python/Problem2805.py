import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    tree = list(map(int, input().split()))
        
    left = 0
    right = max(tree)
    answer = 0
    
    while left <= right:
        mid = (left + right) // 2
        
        total = 0
        for h in tree:
            if h > mid:
                total += h - mid
        
        if total >= M:
            answer = mid
            left = mid + 1
        else:
            right = mid - 1
        
    print(answer)
    
if __name__ == "__main__":
    main()