class Solution {
private:
    void solve(vector<vector<string> > &res, vector<string> &path, int index, string s){
        //Base Case,
        if(index == s.length()){
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                solve(res, path, i+1, s);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end])  return false;
            start++;
            end--;
        }

        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> path;
        int index = 0;
        solve(res, path, index, s);

        return res;
    }
};