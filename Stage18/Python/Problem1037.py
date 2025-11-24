import sys
input = sys.stdin.readline

def main():
    N = int(input())
    divisors = list(map(int, input().split()))
    
    divisors.sort()
    
    if N == 1:
        print(divisors[0] * divisors[0])
    else:
        print(divisors[0] * divisors[-1])
        
if __name__ == "__main__":
    main()