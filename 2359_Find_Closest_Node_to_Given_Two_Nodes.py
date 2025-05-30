from collections import deque

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def bfs(start):
            distances = [-1] * len(edges)
            queue = deque([start])
            distances[start] = 0
            while queue:
                current = queue.popleft()
                neighbor = edges[current]
                if neighbor != -1 and distances[neighbor] == -1:
                    distances[neighbor] = distances[current] + 1
                    queue.append(neighbor)
            return distances
            
        dist1 = bfs(node1)
        dist2 = bfs(node2)

        minDist = float('inf')
        result = -1
        for i in range(len(edges)):
            if dist1[i] != -1 and dist2[i] != -1:
                maxDist = max(dist1[i], dist2[i])
                if maxDist < minDist:
                    minDist = maxDist
                    result = i
        return result                
