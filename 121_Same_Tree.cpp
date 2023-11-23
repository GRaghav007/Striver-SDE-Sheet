class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int x = -1;
        if(p == NULL || q == NULL || p -> val != q -> val)
            return false;
        else{
            if(x == 0)
                return false;
            if(x == 1)
                return true;
            x = isSameTree(p -> left , q -> left);
            x = isSameTree(p -> right, q -> right);
            
        }
         if(x == 0)
                return false;
        else
            return true;
    }
};