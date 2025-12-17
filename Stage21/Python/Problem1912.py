def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    cur = arr[0]
    maxSum = arr[0]
    
    for i in range(1, n):
        cur = max(arr[i], cur + arr[i])
        maxSum = max(maxSum, cur)
    
    print(maxSum)
    
if __name__ == "__main__":
    main()