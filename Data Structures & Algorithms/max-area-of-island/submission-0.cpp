class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> is_visited(rows, vector<bool>(cols, false));
        int max = 0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(!is_visited[i][j] && grid[i][j]==1)
                {
                    int size = mark_connected_land(i, j, rows, cols, grid, is_visited);
                    if (size > max) max = size;
                }
            }
        }
        return max;
    }

    int mark_connected_land(int i, int j, int rows, int cols, vector<vector<int>>& grid, vector<vector<bool>>& is_visited)
    {
        // 1. Base Case: If out of bounds, already visited, or is water ('0'), stop.
        if (!is_safe_index(i, j, rows, cols) || is_visited[i][j] || grid[i][j] == 0)
        {
            return 0;
        }

        // 2. Mark the current cell as visited
        is_visited[i][j] = true;

        // 3. Recursively visit all 4 neighbors
        return 1 + mark_connected_land(i + 1, j, rows, cols, grid, is_visited) +
        mark_connected_land(i - 1, j, rows, cols, grid, is_visited) +
        mark_connected_land(i, j + 1, rows, cols, grid, is_visited) +
        mark_connected_land(i, j - 1, rows, cols, grid, is_visited);
    }

    bool is_safe_index(int i, int j, int rows, int cols)
    {
        return (i>=0 && i<rows && j>=0 && j<cols);
    }
};
