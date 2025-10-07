def main():
    N = int(input())
    numbers = [int(input()) for _ in range(N)]
    numbers.sort()

    for num in numbers:
        print(num)

if __name__ == "__main__":
    main()