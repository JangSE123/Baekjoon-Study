def main():
    N = int(input())
    
    for i in range(1, 10, 1):
        result = N * i
        # print("%d * %d = %d" %(N, i, result))
        print(f"{N} * {i} = {result}")
    
if __name__ == "__main__":
    main()