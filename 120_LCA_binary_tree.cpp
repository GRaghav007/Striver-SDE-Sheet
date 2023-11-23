class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)    return NULL;

        TreeNode* left, *right;
        left = lowestCommonAncestor(root -> left, p, q);
        right = lowestCommonAncestor(root -> right, p, q);
        if(root -> val == p -> val || root -> val == q -> val)    return root;
        if(left && right)   return root;
        if(left && !right)  return left;
        else if(right && !left)    return right;
        return NULL;
    }
};