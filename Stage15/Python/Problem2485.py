import math

def main():
    N = int(input())
    
    trees = [int(input()) for _ in range(N)]
    distances = [trees[i + 1] - trees[i] for i in range(N - 1)]
    
    gcd = distances[0]
    
    for d in distances[1:]:
        gcd = math.gcd(gcd, d)
    
    total = (trees[-1] - trees[0]) // gcd + 1
    print(total - N)

if __name__ == "__main__":
    main()