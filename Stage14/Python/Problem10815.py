import sys
input = sys.stdin.readline

def main():
    N = int(input())
    cards = set(map(int, input().split()))
    
    M = int(input())
    targets = list(map(int, input().split()))
    
    for num in targets:
        print(1 if num in cards else 0, end=' ')
    
if __name__ == "__main__":
    main()