class Solution {
private:
    void solve(int i, int n, vector<vector<int>> &res, vector<int> &x, int k, vector<int> &temp){
        if(i >= n){
            if(k == 0){
                res.push_back(temp);
            }
            return;
        }

        if(x[i] <= k){
            // k -= x[i]; //It is wrong as it will modify the value of target at the current function call
            temp.push_back(x[i]);
            solve(i, n, res, x, k-x[i], temp);
            temp.pop_back();
        }
       
            solve(i+1, n, res, x, k, temp);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& x, int k) {
        int i = 0, n = x.size();
        vector<vector<int>> res;
        vector<int> temp;
        solve(i, n, res, x, k, temp);
        return res;
    }
};