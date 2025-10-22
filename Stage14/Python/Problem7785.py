def main():
    n = int(input())
    people = set()
    
    for _ in range(n):
        name, action = input().split()
        if action == 'enter':
            people.add(name)
        else:
            people.discard(name)
    
    for name in sorted(people, reverse=True):
        print(name)
    
if __name__ == "__main__":
    main()