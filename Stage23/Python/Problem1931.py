import sys
input = sys.stdin.readline

def main():
    N = int(input())
    meetings = []

    for _ in range(N):
        s, e = map(int, input().split())
        meetings.append((s, e))

    meetings.sort(key=lambda x: (x[1], x[0]))

    count = 0
    end_time = 0

    for s, e in meetings:
        if s >= end_time:
            count += 1
            end_time = e

    print(count)
    
if __name__ == "__main__":
    main()