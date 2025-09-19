def main():
    X = int(input())
    line = 1
    count = 0
    
    while count + line < X:
        count += line
        line += 1
        
    index_line = X - count
    
    if line % 2 == 0:
        numerator = index_line
        denominator = line - index_line + 1
    else:
        numerator = line - index_line + 1
        denominator = index_line
    
    print(f"{numerator}/{denominator}")
    
if __name__ == "__main__":
    main()