class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> res(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); ++i){
            if(res[nums[i]] == 0)   res[nums[i]]++;
            else    return nums[i];
        }

        return 0;
    }
};