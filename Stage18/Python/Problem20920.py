import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    word_count = {}

    for _ in range(N):
        word = input().strip()
        if len(word) < M:
            continue
        word_count[word] = word_count.get(word, 0) + 1

    sorted_words = sorted(
        word_count.keys(),
        key=lambda w: (-word_count[w], -len(w), w)
    )

    print("\n".join(sorted_words))
        
if __name__ == "__main__":
    main()