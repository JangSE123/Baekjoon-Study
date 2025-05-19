def main():
    while True:
        try:
            A, B = map(int, input().split())
            print(A + B)
        except EOFError:
            break
    
if __name__ == "__main__":
    main()