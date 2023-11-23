class Solution {
private:
    int solve(TreeNode* root, int k, int &i){
        if(root == NULL)    return -1;
        

        int left = solve(root -> left, k, i);
        if(left != -1)  return left;
        i++;
        if(i == k)  return root -> val;
        int right = solve(root -> right, k, i);
        if(right != -1) return right;
        return -1; 

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)    return -1;
        int i = 0;
        return solve(root, k, i);
    }
};