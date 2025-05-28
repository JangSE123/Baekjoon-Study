def main():
    T = int(input())
    
    for _ in range(T):
        str = input()
        print(str[0] + str[-1])

if __name__ == "__main__":
    main()