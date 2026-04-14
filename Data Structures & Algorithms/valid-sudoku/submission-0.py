class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()
        
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                
                if val == ".":
                    continue
                
                # Create unique identifiers for this specific number's location
                row_id = f"{val} in row {r}"
                col_id = f"{val} in col {c}"
                box_id = f"{val} in box {r // 3}-{c // 3}"
                
                # If we've seen any of these identifiers before, the board is invalid
                if row_id in seen or col_id in seen or box_id in seen:
                    return False
                
                # Otherwise, add them to our memory
                seen.add(row_id)
                seen.add(col_id)
                seen.add(box_id)
                
        return True