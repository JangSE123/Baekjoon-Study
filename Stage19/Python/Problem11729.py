import sys
input = sys.stdin.readline

def hanoi(n, start, mid, end, result):
    if n == 1:
        result.append(f"{start} {end}")
        return
    hanoi(n - 1, start, end, mid, result)
    result.append(f"{start} {end}")
    hanoi(n - 1, mid, start, end, result)

def main():
    n = int(input())
    result = []
    hanoi(n, 1, 2, 3, result)
    print(len(result))
    print("\n".join(result))

if __name__ == "__main__":
    main()