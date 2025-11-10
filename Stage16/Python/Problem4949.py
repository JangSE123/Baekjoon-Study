import sys
input = sys.stdin.readline

def is_balanced(s: str) -> bool:
    stack = []
    
    for ch in s:
        if ch in '([':
            stack.append(ch)
        elif ch == ')':
            if not stack or stack[-1] != '(':
                return False
            stack.pop()
        elif ch == ']':
            if not stack or stack[-1] != '[':
                return False
            stack.pop()

    return not stack

def main():

    while True:
        s = input().rstrip()
        
        if s == '.':
            break
        
        print("yes" if is_balanced(s) else "no")

if __name__ == "__main__":
    main()