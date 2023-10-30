class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        if(s.length() == 0) return 0;
        int res = 1;
        map<char, int> x;
        int j = 0, i = 0;
        for(i = 0; i < s.length(); i++){
            if(x[s[i]] <= 0){
                x[s[i]]++;
            }
            else{
                if(s[i] == s[j]){
                    res = max(res, i - j);
                    x[s[j]]--;    
                    j++; 
                    i--;
                }
                else{
                    res = max(res, i - j);
                    x[s[j]]--;
                    j++; 
                    i--;
                }
            }
        }
        res = max(res, i - j); 
        return res;
    }
};