from collections import deque

def main():
    N = int(input())
    nums = list(map(int, input().split()))

    queue = deque(nums)
    stack = []

    cur = 1

    while queue:
        if queue[0] == cur:
            queue.popleft()
            cur += 1
        elif stack and stack[-1] == cur:
            stack.pop()
            cur += 1
        else:
            stack.append(queue.popleft())

    while stack and stack[-1] == cur:
        stack.pop()
        cur += 1

    if cur == N + 1:
        print("Nice")
    else:
        print("Sad")
    
if __name__ == "__main__":
    main()