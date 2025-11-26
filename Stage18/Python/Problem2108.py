import sys
input = sys.stdin.readline

def main():
    N = int(input())
    nums = []
    freq = [0] * 8001

    _sum = 0
    for _ in range(N):
        x = int(input())
        nums.append(x)
        _sum += x
        freq[x + 4000] += 1

    avg = round(_sum / N)

    nums.sort()
    mid = nums[N // 2]

    max_freq = max(freq)
    count = 0
    mode = 0
    for i in range(8001):
        if freq[i] == max_freq:
            mode = i - 4000
            count += 1
            if count == 2:
                break

    range_val = nums[-1] - nums[0]

    print(avg)
    print(mid)
    print(mode)
    print(range_val)

if __name__ == "__main__":
    main()