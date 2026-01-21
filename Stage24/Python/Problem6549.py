import sys
input = sys.stdin.readline

def main():
    while True:
        line = input().split()
        if not line:
            break

        n = int(line[0])
        if n == 0:
            break

        h = list(map(int, line[1:]))

        stack = []
        max_area = 0

        for i in range(n):
            while stack and h[stack[-1]] > h[i]:
                height_idx = stack.pop()
                height = h[height_idx]

                if not stack:
                    width = i
                else:
                    width = i - stack[-1] - 1

                max_area = max(max_area, height * width)

            stack.append(i)

        while stack:
            height_idx = stack.pop()
            height = h[height_idx]

            if not stack:
                width = n
            else:
                width = n - stack[-1] - 1

            max_area = max(max_area, height * width)

        print(max_area)
        
if __name__ == "__main__":
    main()