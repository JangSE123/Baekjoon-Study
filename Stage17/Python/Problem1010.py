import math

def main():
    T = int(input())
    
    for _ in range(T):
        N, M = map(int, input().split())
        print(math.comb(M, N))
    
if __name__ == "__main__":
    main()