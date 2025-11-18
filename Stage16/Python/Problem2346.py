from collections import deque
import sys
input = sys.stdin.readline

def main():
    N = int(input())
    nums = list(map(int, input().split()))
    
    dq = deque((i+1, nums[i]) for i in range(N))
    result = []
    
    while dq:
        idx, move = dq.popleft()
        result.append(idx)
        
        if move > 0:
            dq.rotate(-(move-1))
        else:
            dq.rotate(-move)
    
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()