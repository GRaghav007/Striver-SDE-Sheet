
class Solution {
public:
    int strStr(string haystack, string needle) {
        string x = "";
        int pos = -1;
        int i = 0;
        while(i < haystack.size()){
            x += haystack[i];

            if(i >= needle.size()){
                x.erase(0, 1);
            }

            if(x == needle){
                pos = i - needle.size() + 1;
                break;
            }
            i++;
        }

        return pos;
    }
};