lass Solution {
private:
    void solve(vector<int> nums, vector<vector<int> > &ans, vector<int> &ds, int index, int n){
        if(index >= n){
            ans.push_back(ds);
            return;
        }

        for(int i = index; i < n; i++){
            swap(nums[index], nums[i]);
            ds.push_back(nums[index]);
            solve(nums, ans, ds, index+1, n);
            swap(nums[index], nums[i]); //Such that, it comes back to it's normal pos
            ds.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> ds;
        int n= nums.size(), index = 0;
        
        solve(nums, ans, ds, index, n);
        return ans;
    }
};