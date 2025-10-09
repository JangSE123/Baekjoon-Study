def main():
    N = input().strip()
    digits = sorted(N, reverse = True)
    print(''.join(digits))

if __name__ == "__main__":
    main()