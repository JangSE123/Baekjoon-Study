def main():
    year = int(input())
    
    leapYear = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
    print(int(leapYear))
    
if __name__ == "__main__":
    main()