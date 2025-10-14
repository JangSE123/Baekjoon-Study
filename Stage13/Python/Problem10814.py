import sys

def main():
    N = int(sys.stdin.readline())
    people = []
    
    for _ in range(N):
        age, name = sys.stdin.readline().split()
        people.append((int(age), name))
        
    people.sort(key=lambda x: x[0])
    
    for age, name in people:
        print(age, name)
    
if __name__ == "__main__":
    main()