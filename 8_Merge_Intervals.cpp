class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& x) {
        if(x.size() <= 1)   return x;

        sort(x.begin(), x.end());
        int i = 0;
        while(i < x.size() - 1){
            if((x[i+1][0] >= x[i][0] && x[i+1][0] <= x[i][1]) || (x[i+1][1] >= x[i][0] && x[i+1][1] <= x[i][1])){
                x[i][1] = max(x[i][1], x[i+1][1]);
                x.erase(x.begin()+i+1);
            }
            else{
                i++;
            }
        }
        return x;
    }
};