def main():
    word = input()
    
    if word == word[::-1]:
        print(1)
    else:
        print(0)
    
if __name__ == "__main__":
    main()