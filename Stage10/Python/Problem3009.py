def main():
    x_list = []
    y_list = []
    
    for _ in range(3):
        x, y = map(int, input().split())
        x_list.append(x)
        y_list.append(y)
        
    for i in x_list:
        if x_list.count(i) == 1:
            x4 = i
    for i in y_list:
        if y_list.count(i) == 1:
            y4 = i

    print(x4, y4)
    
if __name__ == "__main__":
    main()