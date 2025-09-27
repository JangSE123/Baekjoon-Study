def main():
    side1, side2, side3 = map(int, input().split())
    sides = sorted([side1, side2, side3])
    x, y, z = sides
    
    if x + y > z:
        print(x + y + z)
    else:
        print(2 * (x + y) - 1)
    
if __name__ == "__main__":
    main()