import sys

def main():
    input = sys.stdin.readline
    T = int(input())
    results = []
    
    for _ in range(T):
        A, B = map(int, input().rstrip().split())
        results.append(f"{A + B}\n")
    
    sys.stdout.write(''.join(results))
    
if __name__ == "__main__":
    main()