def main():
    T = int(input())
    results = []
    
    for _ in range(T):
        A, B = map(int, input().split())
        results.append(A + B)
    
    for i in range(T):
        print(results[i])
    
if __name__ == "__main__":
    main()