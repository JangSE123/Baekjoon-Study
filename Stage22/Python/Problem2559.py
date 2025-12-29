import sys
input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    
    cur = sum(arr[:K])
    max_sum = cur
    
    for i in range(K, N):
        cur = cur - arr[i - K] + arr[i]
        if cur > max_sum:
            max_sum = cur

    print(max_sum)
    
if __name__ == "__main__":
    main()