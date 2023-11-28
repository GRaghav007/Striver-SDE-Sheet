class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, cand1 = 0, cand2 = 0;
        
        //First pass to find the potential 2 Candidates,
        for(int i = 0; i < nums.size(); ++i){
            if(count1 == 0 && nums[i] != cand2){
                count1 = 1;
                cand1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != cand1){
                count2 = 1;
                cand2 = nums[i];
            }
            else if(nums[i] == cand1)    count1++;
            else if(nums[i] == cand2)   count2++;
            else{
                count1--;
                count2--;
            }
        }

        vector<int> res;
        count1 = 0, count2 = 0;
        int threshold = (nums.size() / 3);
        for(int i = 0; i < nums.size(); ++i){
            if(cand1 == nums[i])    count1++;
            else if(cand2 == nums[i])   count2++;
        }
        if(count1 > threshold)  res.push_back(cand1);
        if(count2 > threshold)  res.push_back(cand2);

        return res;

    }
};