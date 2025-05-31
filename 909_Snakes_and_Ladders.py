from collections import deque
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        
        def getCoordiantes(square):
            row = (square - 1) // n
            col = (square - 1) % n
            if row % 2 == 1:
                col = n - 1 - col
            return n - 1 - row, col
    
        queue = deque([(1, 0)])

        visited = set()

        while queue:
            square, moves = queue.popleft()

            if square == n * n:
            
                return moves

            for diceRoll in range(1, 7):

                nextSquare = square + diceRoll
                if nextSquare > n*n:
                    continue

                r, c = getCoordiantes(nextSquare)
                if board[r][c] != -1:

                    nextSquare = board[r][c]

                if nextSquare not in visited:
                    visited.add(nextSquare)
                    queue.append((nextSquare, moves + 1))
    
        return -1
