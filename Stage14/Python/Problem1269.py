import sys
input = sys.stdin.readline

def main():
    A, B = map(int, input().split())
    
    setA = set(input().split())
    setB = set(input().split())
    
    print(len(setA ^ setB))

if __name__ == "__main__":
    main()