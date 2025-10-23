import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    nameToNum = {}
    numToName = {}
    
    for i in range(1, N + 1):
        name = input().strip()
        nameToNum[name] = i
        numToName[str(i)] = name
    
    for _ in range(M):
        q = input().strip()
        if q[0].isdigit():
            print(numToName[q])
        else:
            print(nameToNum[q])
    
if __name__ == "__main__":
    main()