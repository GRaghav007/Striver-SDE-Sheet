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

int find_pos(vector<int>& inorder, int size, int x){
    for(int i = 0; i < size; i++){
        if(inorder[i] == x)
            return i;
    }

    return -1;
}

TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postInd, int start, int end){
    if(start > end || postInd < 0)
        return NULL;

    int x = postorder[postInd--];
    TreeNode* root = new TreeNode(x); 
    cout << root -> val << " ";  
    int inPos = find_pos(inorder, inorder.size(), x);

    root -> right = solve(inorder, postorder, postInd, inPos + 1, end);
    root -> left = solve(inorder, postorder, postInd, start, inPos - 1);
    
    return root;
}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postInd = postorder.size() - 1;
        int start = 0, end = inorder.size() - 1;
        TreeNode* root = solve(inorder, postorder, postInd, start, end);

        return root;
    }
};