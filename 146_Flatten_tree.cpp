class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)    return;

        TreeNode* curr = root;
        while(curr){
            if(curr -> left){
                TreeNode* pred = curr -> left;
                while(pred -> right)    pred = pred -> right;
                pred -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};