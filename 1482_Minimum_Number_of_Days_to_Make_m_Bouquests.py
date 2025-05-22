class Solution:
    def minDays(self, bloomDay, m, k):
        if len(bloomDay) < m * k:
            return -1

        def getBouquetCount(waitingDays):
            bouquetCount = 0
            requiredFlowers = k
            for day in bloomDay:
                if day > waitingDays:
                    requiredFlowers = k
                else:
                    requiredFlowers -= 1
                    if requiredFlowers == 0:
                        bouquetCount += 1
                        requiredFlowers = k
            return bouquetCount

        l = min(bloomDay)
        r = max(bloomDay)
        while l < r:
            mid = (l + r) // 2
            if getBouquetCount(mid) >= m:
                r = mid
            else:
                l = mid + 1

        return l
