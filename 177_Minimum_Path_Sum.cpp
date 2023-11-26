class Solution {
private:

    int solveByTabu(int row, int col, vector<vector<int>> grid){
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = INT_MAX;
                if(i-1 >= 0)  up = grid[i][j] + dp[i-1][j];
                int left = INT_MAX;
                if(j-1 >= 0) left =  grid[i][j] + dp[i][j-1];

                dp[i][j] = min(up, left);
            }
        }

        return dp[row-1][col-1];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int result;
        int rowSize = grid.size(), colSize  = grid[0].size();
        result = solveByTabu(rowSize, colSize, grid);

        return result;
    }
};