import sys
input = sys.stdin.readline

def main():
    S = input().rstrip()
    n = len(S)
    
    prefix = [[0] * n for _ in range(26)]
    
    for i in range(n):
        c = ord(S[i]) - ord('a')
        for j in range(26):
            prefix[j][i] = prefix[j][i - 1] if i > 0 else 0
        prefix[c][i] += 1
    
    q = int(input())
    
    for _ in range(q):
        ch, l, r = input().split()
        l, r = int(l), int(r)
        idx = ord(ch) - ord('a')
        
        if l == 0:
            print(prefix[idx][r])
        else:
            print(prefix[idx][r] - prefix[idx][l - 1])

if __name__ == "__main__":
    main()