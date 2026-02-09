import sys
import heapq

input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    
    jewels = []
    for _ in range(N):
        M, V = map(int, input().split())
        jewels.append((M, V))
    
    jewels.sort()
    
    bags = [int(input()) for _ in range(K)]
    
    bags.sort()
    
    pq = []
    idx = 0
    total = 0
    
    for bag in bags:
        while idx < N and jewels[idx][0] <= bag:
            heapq.heappush(pq, -jewels[idx][1])
            idx += 1
            
        if pq:
            total += -heapq.heappop(pq)
    
    print(total)
    
if __name__ == "__main__":
    main()