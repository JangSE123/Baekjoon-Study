def isGroupWord(word):
    used = set()
    prev = ''
    
    for curr in word:
        if curr != prev:
            if curr in used:
                return False
            used.add(curr)
        prev = curr
    
    return True

def main():
    N = int(input())
    count = 0
    
    for i in range(N):
        word = input()
        if isGroupWord(word):
            count += 1
    
    print(count)
    
if __name__ == "__main__":
    main()