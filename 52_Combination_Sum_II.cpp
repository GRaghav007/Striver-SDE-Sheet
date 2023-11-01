
class Solution {
private:
    void solve(vector<vector<int>> &res, vector<int>& x, vector<int> &temp, int i, int n, int k){
            if(k == 0){  res.push_back(temp);
            return;}
        

        for(int a = i; a < n; a++){
            if(a > i && x[a] == x[a-1]) continue;
            if(x[a] > k)   break;
            temp.push_back(x[a]);
            solve(res, x, temp, a+1, n, k-x[a]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& x, int k) {
        sort(x.begin(), x.end());
        vector<vector<int>> res;
        vector<int> temp;
        int i = 0, n = x.size();
        solve(res, x, temp, i, n, k);

        return res;
    }
};