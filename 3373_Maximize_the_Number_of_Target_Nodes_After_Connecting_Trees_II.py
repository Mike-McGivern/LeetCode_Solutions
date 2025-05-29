from typing import List

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        # Helper function to build adjacency list from edges
        def build(edges: List[List[int]]) -> List[List[int]]:
            n = len(edges) + 1  # Number of nodes
            adjacency_list = [[] for _ in range(n)]
            for u, v in edges:
                adjacency_list[u].append(v)  # Add edge u to v
                adjacency_list[v].append(u)  # Add edge v to u (undirected)
            return adjacency_list

        # Depth-First Search to label nodes and count nodes in each label
        def dfs(adjacency_list: List[List[int]], current: int, parent: int, labels: List[int], label: int, label_count: List[int]):
            labels[current] = label  # Assign label to current node
            label_count[label] += 1  # Increment count of current label
            for neighbor in adjacency_list[current]:
                if neighbor != parent:
                    dfs(adjacency_list, neighbor, current, labels, 1 - label, label_count)

        # Build adjacency lists for both trees
        tree1 = build(edges1)
        tree2 = build(edges2)

        # Initialize label arrays and counts
        n, m = len(tree1), len(tree2)
        labels1, labels2 = [-1] * n, [-1] * m
        label_count1, label_count2 = [0, 0], [0, 0]

        # Run DFS to label nodes and count parity groups
        dfs(tree1, 0, -1, labels1, 0, label_count1)
        dfs(tree2, 0, -1, labels2, 0, label_count2)

        # Compute the maximum number of target nodes for each node in tree1
        result = [0] * n
        for i in range(n):
            result[i] = label_count1[labels1[i]] + max(label_count2)

        return result
