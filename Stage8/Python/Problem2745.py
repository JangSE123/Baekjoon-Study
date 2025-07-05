def main():
    N, B = input().split()
    B = int(B)
    
    result = 0
    power = 1
    
    for c in reversed(N.upper()):
        if '0' <= c <= '9':
            value = ord(c) - ord('0')
        else:
            value = ord(c) - ord('A') + 10
        
        result += value * power
        power *= B
    
    print(result)
    
if __name__ == "__main__":
    main()