class Solution {
private:
    bool solve(vector<int> nums, int index, vector<vector<int>> &dp, int sum){
        if(index == 0){
            if(sum == nums[0])  return 1;
            return 0;
        }
        if(dp[index][sum] != -1)   return dp[index][sum];
        bool take = 0;
        if(sum >= nums[index])  take = solve(nums, index-1, dp, sum-nums[index]);
        bool notTake  = solve(nums, index-1, dp, sum);

        return dp[index][sum] = (take || notTake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }

        if(sum % 2 != 0)    return false;

        vector<vector<int>> dp(nums.size(), vector<int>((sum/2)+1, 0));
        // bool result = solve(nums, nums.size()-1, dp, sum/2);

        for(int i = 0; i < nums.size(); ++i){
            if((sum/2) >= nums[i])dp[i][nums[i]] = 1;
        }

        for(int i = 0; i <= (sum/2); ++i){
            if(nums[0] == i)    dp[0][i] = 1;
            else    dp[0][i] = 0;
        }

        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j <= (sum/2); ++j){
                bool take = 0;
                if(j >= nums[i])  take = dp[i-1][j-nums[i]];
                bool notTake  = dp[i-1][j];

                dp[i][j] = (take || notTake);
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};