def main():
    matrix = [list(map(int, input().split())) for _ in range(9)]
    
    maxValue, row, col = -1, 0, 0
    
    for i, line in enumerate(matrix):
        for j, val in enumerate(line):
            if val > maxValue:
                maxValue = val
                row = i + 1
                col = j + 1
    
    print(maxValue)
    print(row, col)
    
if __name__ == "__main__":
    main()