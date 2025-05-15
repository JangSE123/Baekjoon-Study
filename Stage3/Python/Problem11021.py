import sys
def main():
    input = sys.stdin.readline
    T = int(input())
    results = []
    
    for i in range(1, T + 1):
        A, B = map(int, input().rstrip().split())
        results.append(f"Case #{i}: {A + B}\n")
    
    sys.stdout.write(''.join(results))
    
if __name__ == "__main__":
    main()