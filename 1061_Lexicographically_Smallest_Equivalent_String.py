class UnionFind:
    def __init__(self):
        self.parent = {chr(i) : chr(i) for i in range(97, 123)}
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if rootX < rootY:
                self.parent[rootY] = rootX
            else:
                self.parent[rootX] = rootY

class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        uf = UnionFind()

        for a, b in zip(s1, s2):
            uf.union(a, b)

        return ''.join(uf.find(c) for c in baseStr)
