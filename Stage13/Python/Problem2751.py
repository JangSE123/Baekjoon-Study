import sys

def main():
    input = sys.stdin.readline
    
    N = int(input())
    numbers = [int(input()) for _ in range(N)]
    numbers.sort()
    
    sys.stdout.write('\n'.join(map(str, numbers)))

if __name__ == "__main__":
    main()