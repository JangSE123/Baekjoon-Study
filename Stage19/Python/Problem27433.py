def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

def main():
    N = int(input())
    
    print(factorial(N))
    
if __name__ == "__main__":
    main()