import sys
input = sys.stdin.readline

N = int(input())
count = 0

col = [0] * N
used_col = [False] * N
used_diag1 = [False] * (2 * N)
used_diag2 = [False] * (2 * N)

def dfs(row):
    global count
    if row == N:
        count += 1
        return

    for c in range(N):
        if not used_col[c] and not used_diag1[row + c] and not used_diag2[row - c + N]:
            used_col[c] = used_diag1[row + c] = used_diag2[row - c + N] = True
            dfs(row + 1)
            used_col[c] = used_diag1[row + c] = used_diag2[row - c + N] = False

dfs(0)
print(count)