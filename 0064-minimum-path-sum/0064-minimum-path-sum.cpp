class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Create a 2D DP array with the same dimensions as grid
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        // Initialize the top-left corner with the same value as in the grid
        dp[0][0] = grid[0][0];
        
        // Initialize the first row
        for (int j = 1; j < cols; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        
        // Initialize the first column
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        // Fill in the rest of the dp array
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        // The bottom-right corner will contain the minimum path sum
        return dp[rows - 1][cols - 1];
    }
};
