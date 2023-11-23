class Solution {
    private:
    void solve(Node* root, vector<Node*> &level){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            level.push_back(temp);
            if(temp == NULL){
                if(!q.empty())  q.push(NULL);
            }
            else{
                if(temp -> left)    q.push(temp -> left);
                if(temp -> right)   q.push(temp -> right);
            }
        }

    }

public:
    Node* connect(Node* root) {
        if(root == NULL)    return root;
        vector<Node*> level;
        solve(root, level);

        for(int i = 0; i < level.size() -1; i++){
            if(level[i] == NULL)    continue;
            level[i] -> next = level[i + 1];
        }

        return root;
    }
};