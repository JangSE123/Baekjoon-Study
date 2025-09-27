def main():
    while True:
        side1, side2, side3 = map(int, input().split())

        if side1 == 0 and side2 == 0 and side3 == 0:
            break
        
        sides = [side1, side2, side3]
        max_side = max(sides)
        total = sum(sides)
        
        if total - max_side <= max_side:
            print("Invalid")
        elif side1 == side2 == side3:
            print("Equilateral")
        elif side1 == side2 or side2 == side3 or side1 == side3:
            print("Isosceles")
        else:
            print("Scalene")
            
    
if __name__ == "__main__":
    main()