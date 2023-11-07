class Solution {
public:
    string reverseWords(string s) {
        vector<string> x;
        string a;
        int j;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                a = "";
                j = i;
                while(s[j] != ' ' && j < s.length()){   
                     a += s[j++];
                }
                
                i = j - 1;

                x.push_back(a);
            }
        }

        string res;
 
        for(int i = x.size() - 1; i >= 0; i--){
            res += x[i];
            if(i != 0)  res += ' ';
        }

        return res;
    }
};