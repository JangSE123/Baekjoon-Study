import sys

def main():
    n = int(sys.stdin.readline().strip())

    fib = [0] * (n + 1)
    fib[1] = fib[2] = 1
    for i in range(3, n + 1):
        fib[i] = fib[i - 1] + fib[i - 2]

    count_rec = fib[n]
    count_dp = n - 2

    print(count_rec, count_dp)

if __name__ == "__main__":
    main()