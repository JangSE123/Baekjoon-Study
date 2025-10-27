import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    
    heard = set(input().strip() for _ in range(N))
    seen = set(input().strip() for _ in range(M))
    
    result = sorted(heard & seen)
    
    print(len(result))
    print("\n".join(result))
    
if __name__ == "__main__":
    main()