def main():
    N = int(input())
    
    points = [tuple(map(int, input().split())) for _ in range(N)]
    
    xs = [x for x, _ in points]
    ys = [y for _, y in points]
    
    print((max(xs) - min(xs)) * (max(ys) - min(ys)))
    
if __name__ == "__main__":
    main()