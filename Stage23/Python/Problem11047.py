import sys
input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    coins = [int(input()) for _ in range(N)]
    
    count = 0
    
    for c in reversed(coins):
        if K == 0:
            break
        count += K // c
        K %= c

    print(count)
    
if __name__ == "__main__":
    main()