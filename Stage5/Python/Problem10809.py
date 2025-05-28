def main():
    S = input()
    alphabet = [-1] * 26
    
    for i, c in enumerate(S):
        idx = ord(c) - ord('a')
        if alphabet[idx] == -1:
            alphabet[idx] = i
    
    print(*alphabet)
    
    # print(*[S.find(chr(i + ord('a'))) for i in range(26)])
    
if __name__ == "__main__":
    main()
