import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))

    count = [0] * M
    s = 0
    answer = 0

    for x in arr:
        s += x
        mod = s % M

        if mod == 0:
            answer += 1

        count[mod] += 1

    for c in count:
        if c >= 2:
            answer += c * (c - 1) // 2

    print(answer)
    
if __name__ == "__main__":
    main()