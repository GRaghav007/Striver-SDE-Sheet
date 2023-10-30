class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > x;
        for(int i = 0; i < nums.size(); i++){
            x.push_back(make_pair(nums[i], i));
        }
        sort(x.begin(), x.end());
        int i = 0, j = x.size() - 1;
        while(i < j){
            if(x[i].first+x[j].first == target)
                return {x[i].second, x[j].second};
            else if(x[i].first+x[j].first < target) i++;
            else    j--;
        }

        return {-1, -1};
    }
};