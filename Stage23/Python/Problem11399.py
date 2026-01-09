import sys
input = sys.stdin.readline

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    arr.sort()
    
    total = 0
    prefix = 0
    for x in arr:
        prefix += x
        total += prefix
    
    print(total)
    
if __name__ == "__main__":
    main()