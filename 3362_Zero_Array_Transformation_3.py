import heapq
class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        totalQueries = len(queries)
        diff = [0] * (n + 1)
        currentExtra = 0
        chosen = 0

        queriesSorted = sorted(queries, key=lambda x: x[0])
        heap = []
        j = 0

        for i in range(n):
            if i > 0:
                currentExtra += diff[i]

            while j < len(queriesSorted) and queriesSorted[j][0] <=i:
                heapq.heappush(heap, -queriesSorted[j][1])
                j += 1
            
            required = nums[i] - currentExtra
            while required > 0:
                while heap and -heap[0] < i:
                    heapq.heappop(heap)
                if not heap:
                    return -1
                bestR = -heapq.heappop(heap)
                chosen += 1
                diff[i] += 1
                if bestR + 1 < len(diff):
                    diff[bestR + 1] -= 1
                currentExtra += 1
                required -= 1
        
        return totalQueries - chosen
