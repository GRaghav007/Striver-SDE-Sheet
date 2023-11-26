class Solution {
private:
    int solve(vector<int> coins, int n, int target){

        vector<vector<int>> dp(coins.size(), vector<int>(target+1, -1));
        for(int i = 0; i < n; ++i)  dp[i][0] = 0;
        for(int i = 1; i <= target; ++i){
            if(i%coins[0] == 0) dp[0][i] = i/coins[0]; 
        }

        for(int i = 1; i < n; ++i){
            for(int j = 1; j <= target; ++j){
                int notPick = dp[i-1][j];
                int pick = 1e9;
                if(coins[i] <= j)  pick = 1 + dp[i][j-coins[i]];

                if((pick == -1 && notPick == -1) || (pick == 1e9 && notPick == 1e9)) dp[i][j] = -1;
                else if(pick == -1) dp[i][j] = notPick;
                else if(notPick == -1) dp[i][j] = pick;
                else dp[i][j] = min(pick, notPick);
            }
        }

        return dp[n-1][target];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int result;
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -2));
        result = solve(coins, coins.size(), amount);

        return result;
    }
};