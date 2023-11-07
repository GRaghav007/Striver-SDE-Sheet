class Solution {
public:
    bool isValid(string s) {
        if(s.length() <= 1) return false;

        stack<char> x;

        for(int i = 0; i < s.length(); i++){
            if(s[0] == ')' || s[0] == ']' || s[0] == '}')   return false;

            if(s[i] == '(' || s[i] == '[' || s[i] == '{')   x.push(s[i]);

            else if(s[i] == ')'){
                if(x.empty())   return false;
                if(x.top() == '(')  x.pop();
                else    return false;
            }
            else if(s[i] == '}'){
                if(x.empty())   return false;
                if(x.top() == '{')  x.pop();
                else    return false;
            }
            else if(s[i] == ']'){
                if(x.empty())   return false;
                if(x.top() == '[')  x.pop();
                else    return false;
            }
        }

        if(!x.empty())  return false;
        return true;
    }
};