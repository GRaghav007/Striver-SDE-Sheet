class Solution {
public:
    int maxDepth(TreeNode* root) {
        //Base case,
        if(root == NULL){
            return 0;
        }
        int hl = maxDepth(root -> left);
        int hr = maxDepth(root -> right);

        return (max(hl, hr) + 1);

    }
};