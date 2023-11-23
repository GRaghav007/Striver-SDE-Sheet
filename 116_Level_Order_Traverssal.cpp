/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void solve(TreeNode* root, vector<vector<int> > &res){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> x;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                res.push_back(x);
                x.clear();
                if(!q.empty())  q.push(NULL);
            }
            else{
                x.push_back(temp -> val);
                if(temp -> left)    q.push(temp -> left);
                if(temp -> right)    q.push(temp -> right);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL)    return res;
        solve(root, res);

        return res;
    }
};