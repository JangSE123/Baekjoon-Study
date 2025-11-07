import sys
input = sys.stdin.readline

def is_vps(s: str) -> bool:
    stack = []
    
    for ch in s:
        if ch == '(':
            stack.append(ch)
        else:
            if not stack:
                return False
            stack.pop()

    return not stack

def main():
    T = int(input())
    for _ in range(T):
        s = input().strip()
        print("YES" if is_vps(s) else "NO")

if __name__ == "__main__":
    main()