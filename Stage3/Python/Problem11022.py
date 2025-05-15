import sys

def main():
    input = sys.stdin.readline
    T = int(input())
    results = []
    
    for x in range(T):
        A, B = map(int, input().rstrip().split())
        C = A + B
        results.append(f"Case #{x + 1}: {A} + {B} = {C}\n")
        
    sys.stdout.write(''.join(results))  
    
if __name__ == "__main__":
    main()