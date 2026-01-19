import sys
input = sys.stdin.readline

MOD = 1000000007

def multiply(a, b):
    return [
        [
            (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD,
            (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD
        ],
        [
            (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD,
            (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD
        ]
    ]

def power(matrix, exp):
    if exp == 1:
        return matrix

    half = power(matrix, exp // 2)
    ret = multiply(half, half)

    if exp % 2 == 1:
        ret = multiply(ret, matrix)

    return ret

def main():
    n = int(input())

    if n == 0:
        print(0)
        return

    base = [[1, 1], [1, 0]]
    result = power(base, n)

    print(result[0][1])

if __name__ == "__main__":
    main()