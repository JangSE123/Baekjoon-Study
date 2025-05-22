def main():
    B = 42
    mod = [int(input()) % B for _ in range(10)]
    print(len(set(mod)))
    
if __name__ == "__main__":
    main()