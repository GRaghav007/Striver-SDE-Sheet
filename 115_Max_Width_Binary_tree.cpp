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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)    return 0;
        if(root -> left == NULL && root -> right == NULL)   return 1;

        TreeNode* aux = new TreeNode(-101);
        queue<TreeNode*> q;
        vector<TreeNode*> v;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp);

            if(temp == NULL){
                if(!q.empty())  q.push(NULL);
                else    break;
            }

            else if(temp -> val != -101){
                if(temp -> left == NULL && temp -> right == NULL)   continue;
                if(temp -> left && temp -> left != aux)    q.push(temp -> left);
                else    q.push(aux);
                if(temp -> right && temp -> right != aux)   q.push(temp -> right);
                else    q.push(aux);
            }
        }

        for(auto i: v){
            if(i)   cout << i -> val << " ";
            else    cout << "N ";
        }

        return 0;  
    }
};