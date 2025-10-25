import sys
import bisect
input = sys.stdin.readline

def main():
    N = int(input())
    cards = sorted(map(int, input().split()))
    M = int(input())
    targets = list(map(int, input().split()))
    
    result = []
    for t in targets:
        left = bisect.bisect_left(cards, t)
        right = bisect.bisect_right(cards, t)
        result.append(right - left)
        
    print(*result)
    
if __name__ == "__main__":
    main()