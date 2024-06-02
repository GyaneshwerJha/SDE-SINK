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
    vector<vector<int>> res;

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                auto it = q.front();
                temp.push_back(it->val);
                q.pop();

                if(it->left != NULL){
                    q.push(it->left);
                }
                if(it->right != NULL){
                    q.push(it->right);
                }
            }
            res.push_back(temp);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};