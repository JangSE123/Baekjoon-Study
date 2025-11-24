import sys
input = sys.stdin.readline

def main():
    N = int(input())
    group = set()
    count = 0

    for _ in range(N):
        name = input().strip()
        if name == "ENTER":
            group.clear()
        else:
            if name not in group:
                group.add(name)
                count += 1

    print(count)

if __name__ == "__main__":
    main()