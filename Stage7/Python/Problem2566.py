def main():
    matrix = [list(map(int, input().split())) for _ in range(9)]
    
    value, row, col = -1, 0, 0

    for i in range(9):
        for j in range(9):
            if matrix[i][j] > value:
                value = matrix[i][j]
                row = i + 1
                col = j + 1
        
    print(value)
    print(row, col)
    
if __name__ == "__main__":
    main()