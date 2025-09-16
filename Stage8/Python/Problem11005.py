def main():
    N, B =  map(int, input().split())
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    res = ""
    
    while N > 0:
        N, r = divmod(N, B)
        res = digits[r] + res
    
    print(res)
    
if __name__ == "__main__":
    main()