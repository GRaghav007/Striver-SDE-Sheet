class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1)    return 1;
        if(nums.size() == 0)    return 0;

        sort(nums.begin(), nums.end());

        int res = INT_MIN;
        int cnt = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1])    continue;
            else if(nums[i] == nums[i + 1] -1)  cnt++;
            else{
                res = max(res, cnt);
                cnt = 1;
            }
        }
        res = max(res, cnt);

        return res;
    }
};