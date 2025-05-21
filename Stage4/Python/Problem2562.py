def main():
    arr = [int(input()) for _ in range(9)]
    
    max_value = max(arr)
    index = arr.index(max_value) + 1
    
    print(max_value)
    print(index)
    
if __name__ == "__main__":
    main()