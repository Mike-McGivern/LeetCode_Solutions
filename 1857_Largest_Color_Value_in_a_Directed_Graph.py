from collections import deque
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        adj = [[] for _ in range(n)]
        indegree = [0] * n
        count = [[0] * 26 for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1

        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        visit = res = 0
        while q:
            node = q.popleft()
            visit += 1
            colorIndex = ord(colors[node]) - ord('a')
            count[node][colorIndex] += 1
            res = max(res, count[node][colorIndex])

            for nei in adj[node]:
                for c in range(26):
                    count[nei][c] = max(count[nei][c], count[node][c])
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)

        return res if visit == n else -1
