import math

def main():
    A, B = map(int, input().split())
    C, D = map(int, input().split())
    
    numerator = A * D + B * C
    denominator = B * D

    g = math.gcd(numerator, denominator)
    numerator //= g
    denominator //= g
    
    print(numerator, denominator)
    
if __name__ == "__main__":
    main()