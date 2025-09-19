def main():
    N = int(input())
    
    if N == 1:
        print(1)
    else:
        layer = 1
        max_num = 1
        
        while max_num < N:
            max_num += 6 * layer
            layer += 1
        print(layer)
    
if __name__ == "__main__":
    main()