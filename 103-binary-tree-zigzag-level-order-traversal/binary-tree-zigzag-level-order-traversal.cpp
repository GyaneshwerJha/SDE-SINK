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

    void levelOrder(TreeNode *root){
        
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
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return res;

        levelOrder(root);
        for(int i = 1; i < res.size(); i += 2){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};