def main():
    N = int(input())
    scores = list(map(int, input().split()))
    
    M = max(scores)
    newScores = [(score / M) * 100 for score in scores]
    avg = sum(newScores) / N
    
    print(avg)    
    
if __name__ == "__main__":
    main()