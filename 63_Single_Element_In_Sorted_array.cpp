class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == nums[i + 1])
                i += 2;
            else{
                return nums[i];
                break;
            }
        }

        return -1;
    }
};