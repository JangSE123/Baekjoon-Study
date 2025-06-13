def main():
    matrix = [list(map(int, input().split())) for _ in range(9)]
    
    value, row, col = max(
        (matrix[i][j], i, j)
        for i in range(9)
        for j in range(9)
    )
    
    print(value)
    print(row + 1, col + 1)
    
if __name__ == "__main__":
    main()