import math

def main():
    A, B, V = map(int, input().split())
    
    days = math.ceil((V - A) / (A - B)) + 1
    print(days)
    
if __name__ == "__main__":
    main()