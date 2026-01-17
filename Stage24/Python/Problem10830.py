import sys
input = sys.stdin.readline
MOD = 1000

def multiply(m1, m2, N):
    res = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                res[i][j] += m1[i][k] * m2[k][j]
            res[i][j] %= MOD
    return res

def power(matrix, exp, N):
    if exp == 1:
        return matrix

    half = power(matrix, exp // 2, N)
    result = multiply(half, half, N)

    if exp % 2 == 1:
        result = multiply(result, matrix, N)

    return result

def main():
    N, B = map(int, input().split())
    A = [list(map(lambda x: int(x) % MOD, input().split())) for _ in range(N)]
    
    result = power(A, B, N)

    for row in result:
        print(*row)
    
if __name__ == "__main__":
    main()