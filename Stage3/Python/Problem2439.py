def main():
    N = int(input())
    
    for i in range(1, N + 1):
        space = N - i
        star = i
        
        print(" " * space + "*" * star)
    
if __name__ == "__main__":
    main()