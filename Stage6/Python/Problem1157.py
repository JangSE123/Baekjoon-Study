def main():
    word = input().upper()
    alphabet = [0] * 26
    
    for i in word:
        alphabet[ord(i) - ord('A')] += 1
        
    maxValue = max(alphabet)
    
    if alphabet.count(maxValue) > 1:
        print('?')
    else:
        print(chr(alphabet.index(maxValue) + ord('A')))

if __name__ == "__main__":
    main()