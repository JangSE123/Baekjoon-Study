import sys
input = sys.stdin.readline

N = 0
nums = []
op = [0, 0, 0, 0]
max_val = -10**12
min_val = 10**12

def dfs(idx, current):
    global max_val, min_val, nums, op, N

    if idx == N:
        max_val = max(max_val, current)
        min_val = min(min_val, current)
        return

    for i in range(4):
        if op[i] > 0:
            op[i] -= 1

            if i == 0:
                dfs(idx + 1, current + nums[idx])
            elif i == 1:
                dfs(idx + 1, current - nums[idx])
            elif i == 2:
                dfs(idx + 1, current * nums[idx])
            else:
                if current < 0:
                    dfs(idx + 1, -(-current // nums[idx]))
                else:
                    dfs(idx + 1, current // nums[idx])

            op[i] += 1

def main():
    global N, nums, op

    N = int(input())
    nums = list(map(int, input().split()))
    op = list(map(int, input().split()))

    dfs(1, nums[0])

    print(max_val)
    print(min_val)


if __name__ == "__main__":
    main()