def main():
    a1, a0 = map(int, input().split())
    c = int(input())
    n0 = int(input())

    if a1 > c:
        print(0)
    elif a1 == c:
        if a0 <= 0:
            print(1)
        else:
            print(0)
    else:
        if (c - a1) * n0 >= a0:
            print(1)
        else:
            print(0)
    
if __name__ == "__main__":
    main()