def main():
    N = int(input())
    str = input()
    
    total = sum(int(i) for i in str)
    print(total)
    
if __name__ == "__main__":
    main()