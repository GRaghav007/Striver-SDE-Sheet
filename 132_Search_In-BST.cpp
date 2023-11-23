class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)    return NULL;
        if(root -> val == val)  return root;
        TreeNode* res;
        if(root -> val > val){
            res = searchBST(root -> left, val);
        }
        else if(root -> val < val)  res = searchBST(root -> right, val);
        if(res)    return res;
        return NULL;
    }   
};