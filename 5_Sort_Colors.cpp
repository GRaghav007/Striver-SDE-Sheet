class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)    cnt0++;
            else if(nums[i] == 1)    cnt1++;
            else if(nums[i] == 2)    cnt2++;
        }

        int i = 0, j = 0;
        while(i < cnt0){
            nums[j++] = 0;
            i++;
        }
        i = 0;
        while(i < cnt1){
            nums[j++] = 1;
            i++;
        }
        i = 0;
        while(i < cnt2){
            nums[j++] = 2;
            i++;
        }
    }
};