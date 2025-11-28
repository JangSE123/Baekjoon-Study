import sys
input = sys.stdin.readline

def recursion(s, l, r):
    global count
    count += 1
    
    if l >= r:
        return 1
    elif s[l] != s[r]:
        return 0
    else:
        return recursion(s, l + 1, r - 1)

def isPalindrome(s):
    return recursion(s, 0, len(s) - 1)

def main():
    global count
    T = int(input())
    
    for _ in range(T):
        s = input().strip()
        count = 0
        result = isPalindrome(s)
        print(result, count)
        
if __name__ == "__main__":
    main()