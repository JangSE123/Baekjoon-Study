def main():
    A, B = map(int, input().split())

    if 0 < A < 10 and 0 < B < 10:
        print(A + B)
    else:        
        print("입력값이 0보다 크고 10보다 작아야 합니다.")

if __name__ == "__main__":
    main()