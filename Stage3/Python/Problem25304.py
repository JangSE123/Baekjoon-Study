def main():
    X = int(input())
    N = int(input())
    
    totalPrice = 0
    
    for i in range(N):
        a, b = map(int, input().split())
        totalPrice += a * b
    
    print("Yes" if X == totalPrice else "No")
    
if __name__ == "__main__":
    main()