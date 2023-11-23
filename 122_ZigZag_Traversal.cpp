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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        
        vector<int> sub;
        vector<pair<TreeNode*, int> > q;
        q.push_back(make_pair(root, 0));
        while(!q.empty()){
            int i = 0;
            while(i < q.size()){
                sub.push_back(q[i++].first -> val);
            }
            i = q.size() - 1;
            pair<TreeNode*, int> temp = q[0];
            int level = temp.second;
            int initial_size = q.size();
            while(i >= 0){
                if(level % 2 == 0){
                    //Right to left,
                    if(q[i].first -> right){
                        q.push_back(make_pair(q[i].first -> right, level + 1));
                    }
                    if(q[i].first -> left){
                        q.push_back(make_pair(q[i].first -> left, level + 1));
                    }
                }
                else{
                    //Left to right,
                    if(q[i].first -> left){
                        q.push_back(make_pair(q[i].first -> left, level + 1));
                    }
                    if(q[i].first -> right){
                        q.push_back(make_pair(q[i].first -> right, level + 1));
                    }
                }
                i--;
            }
            q.erase(q.begin(), q.begin()+initial_size);
            ans.push_back(sub); 
            sub.clear();
        }
        return ans;
    }
};

/**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
//         vector<vector<int> > ans;
//         vector<int> sub;
//         queue<pair<TreeNode*, int> > q;
//         q.push(make_pair(root, 0));

//         while(!q.empty()){
//             int cnt = 0;
//             while(cnt < q.size()){
//                 pair<TreeNode*, int> x = q.top();
//                 int z = x.second;
//                 TreeNode* y = x.first;
//                 q.pop();
//                 sub.push_back(y -> val);
//                 q.push(make_pair(y, z));
//                 cnt++;
//             }
//             pair<TreeNode*, int> temp = q.top();
//             TreeNode* topNode = temp.first;
//             int level = temp.second;
//             q.pop();
//             if(temp % 2 == 0){
//                 //Left to right,
//                 if(temp -> right)
//                     q.push(make_pair(temp -> right, level + 1));
//                 if(temp -> left)
//                     q.push(make_pair(temp -> left, level + 1));
//             }
//             else{
//                 //Right to left;
//                 if(temp -> left)
//                     q.push(make_pair(temp -> left, level + 1));
//                 if(temp -> right)
//                     q.push(make_pair(temp -> right, level + 1));
//             }
//             ans.push_back(sub);
//             sub.clear();
//         }

//         return ans;
//     }
// };