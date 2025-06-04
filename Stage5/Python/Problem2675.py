def main():
    T = int(input())
    
    for _ in range(T):
        R, S = input().split()
        R = int(R)
        result = ''.join(c * R for c in S)
        print(result)
        
if __name__ == "__main__":
    main()