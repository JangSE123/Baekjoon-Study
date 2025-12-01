import sys

def cantor(arr, start, size):
    if size == 1:
        return
    length = size // 3

    for i in range(start + length, start + 2 * length):
        arr[i] = ' '

    cantor(arr, start, length)
    cantor(arr, start + 2 * length, length)

def main():
    for line in sys.stdin:
        N = int(line.strip())
        size = 3 ** N

        arr = ['-'] * size
        cantor(arr, 0, size)

        print(''.join(arr))

if __name__ == "__main__":
    main()