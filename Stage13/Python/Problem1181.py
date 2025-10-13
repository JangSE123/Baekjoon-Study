import sys

def main():
    N = int(sys.stdin.readline())
    words = list(set(sys.stdin.readline().strip() for _ in range(N)))

    words.sort(key=lambda x:(len(x), x))
    
    for w in words:
        print(w)
    
if __name__ == "__main__":
    main()