

#include <bits/stdc++.h>

class Node {
    public:
    Node* link[26];
    bool flag = false;

    bool containsKey(char ch){
        if(link[ch - 'a'] != NULL)  return true;

        return false;
    }

    void put(char ch, Node* temp){
        link[ch - 'a'] = temp;
    }

    Node* get(char ch){
        return link[ch - 'a'];
    }

    void setFlag(){
        flag = true;
    }

    bool getFlag(){
        return flag;
    }
};

class Trie {
    private:    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }

            node = node -> get(word[i]);
        }
        node -> setFlag();
    }

    bool check(string word){
        Node* node = root;
        bool flag = true;
        for(int i = 0; i < word.length(); i++){
            if(!node -> containsKey(word[i]))   return false;
            node = node -> get(word[i]);

            //Made mistake here,(didn't write it)
            flag = flag & node -> getFlag();
        }

        //Instead of above wrote this,
        // if(node -> getFlag()) return true;
        // return false;
        return flag;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* obj = new Trie();

    for(int i = 0; i < n; i++){
        obj -> insert(a[i]);
    }

    string res = "";

    for(int i = 0; i < n; i++){
        if(obj -> check(a[i])){
            if(res.size() < a[i].size()){
                res = a[i];
            }
            else if(res.size() == a[i].length() && a[i] < res){
                res = a[i];
            }
        }
    }

    if(res == "")   return "None";
    return res;
}