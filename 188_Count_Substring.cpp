class Node{
    public:
    Node* link[26];

    bool containsKey(char ch){
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch, Node* temp){
        link[ch - 'a'] = temp;
    }

    Node* getTrie(char ch){
        return link[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.

    Node* trie = new Node();

    int result = 0;

    for(int i = 0; i < s.length(); i++){
        Node* root = trie;
        for(int j = i; j < s.length(); j++){
            if(!root -> containsKey(s[j])){
                result++;
                root -> put(s[j], new Node());
            }
            root = root -> getTrie(s[j]);
        }
    }

    return result+1;
}