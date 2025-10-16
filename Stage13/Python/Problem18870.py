def main():
    N = int(input())
    X = list(map(int, input().split()))
    
    sorted_unique = sorted(set(X))
    
    rank = {v: i for i, v in enumerate(sorted_unique)}
    
    print(' '.join(str(rank[x]) for x in X))
    
if __name__ == "__main__":
    main()