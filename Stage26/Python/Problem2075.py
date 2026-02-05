import sys
import heapq

input = sys.stdin.readline

def main():
    N = int(input())
    heap = []
    
    for _ in range(N):
        nums = map(int, input().split())
        for x in nums:
            heapq.heappush(heap, x)
            if len(heap) > N:
                heapq.heappop(heap)
    
    print(heap[0])
    
if __name__ == "__main__":
    main()