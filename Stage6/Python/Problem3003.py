def main():
    defaultPieces = [1, 1, 2, 2, 2, 8]
    currentPieces = list(map(int, input().split()))
    
    diff = [d - c for d, c in zip(defaultPieces, currentPieces)]

    print(*diff)
    
if __name__ == "__main__":
    main()