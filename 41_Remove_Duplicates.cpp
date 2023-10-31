class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0, i = 0;
        while(i < nums.size()-1){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i+1);
                cnt++;
            }
            else    i++;
        }

        return n - cnt;
    }
};