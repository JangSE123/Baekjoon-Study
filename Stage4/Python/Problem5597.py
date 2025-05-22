def main():
    students = set(range(1, 31))
    submitted = set(int(input()) for _ in range(28))
    
    missing = sorted(students - submitted)
    
    for num in missing:
        print(num)
    
if __name__ == "__main__":
    main()