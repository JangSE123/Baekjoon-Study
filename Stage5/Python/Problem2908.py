def main():
    A, B = input().split()
    
    revA = int(A[::-1])
    revB = int(B[::-1])
    
    print(max(revA, revB))
    
if __name__ == "__main__":
    main()