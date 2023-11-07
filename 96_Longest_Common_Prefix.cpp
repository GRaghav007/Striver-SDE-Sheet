class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)    return "";

        string res = "";
        res = strs[0];
        for(int i = 1; i < strs.size(); i++){
            int j = 0, k = 0;
            while(j < res.length() && k < strs[i].length()){
                if(res[j] == strs[i][k]){    
                    j++;
                    k++;    
                }
                else{
                    
                    break;
                }
            }
            res.erase(res.begin()+k, res.end());
        }

        return res;
    }
};