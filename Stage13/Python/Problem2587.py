def main():
    arr = [int(input()) for _ in range(5)]
    arr.sort()
    average = sum(arr) // 5
    median = arr[2]
    
    print(average)
    print(median)
    
if __name__ == "__main__":
    main()