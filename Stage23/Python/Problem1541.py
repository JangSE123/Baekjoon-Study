def main():
    s = input().strip()
    
    parts = s.split('-')
    
    result = sum(map(int, parts[0].split('+')))
    
    for p in parts[1:]:
        result -= sum(map(int, p.split('+')))
    
    print(result)

if __name__ == "__main__":
    main()