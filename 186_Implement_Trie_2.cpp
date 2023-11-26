#include <bits/stdc++.h> 


class Node{

    public:

    Node* link[26];
    int cntEndsWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        if(link[ch - 'a'] != NULL)  return true;
        return false;
    }

    void put(char ch, Node* node){
        link[ch - 'a'] = node;
    }   

    Node* get(char ch){
        return link[ch - 'a'];
    }

    void incrementPrefix(){
        cntPrefix++;
    }

    void incrementEndsWith(){
        cntEndsWith++;
    }

    int getCntEndsWith(){
        return cntEndsWith;
    }

    int getCntPrefix(){
        return cntPrefix;
    }

    void decrementCntEndsWith(){
        cntEndsWith--;
    }

    void decrementCntPrefix(){
        cntPrefix--;
    }
};

class Trie{

    private:    Node* root;

    public:

    Trie(){
        
        root = new Node();
    }

    void insert(string &word){
        
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }

            node = node -> get(word[i]);
            node -> incrementPrefix();
        }

        node -> incrementEndsWith();

    }

    int countWordsEqualTo(string &word){
        
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
            }
            else{
                return 0;
            }
        }

        return node -> getCntEndsWith();
    }

    int countWordsStartingWith(string &word){
        
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
            }
            else    return 0;
        }

        return node -> getCntPrefix();
    }

    void erase(string &word){
        //Considering that the word already exists,

        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
                node -> decrementCntPrefix();
            }
            else    return;
        }

        node -> decrementCntEndsWith();
    }
};
