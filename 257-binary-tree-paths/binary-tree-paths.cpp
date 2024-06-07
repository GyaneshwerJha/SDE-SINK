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
    void solve(TreeNode *root, vector<string> &res, string temp){
        if(root->left == NULL && root->right == NULL){
            res.push_back(temp + to_string(root->val));
            return;
        }

        if(root->left != NULL){
            solve(root->left, res, temp + to_string(root->val) + "->");
        }

        if(root->right != NULL){
            solve(root->right, res, temp + to_string(root->val) + "->");
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        string temp = "";
        solve(root, res, temp);
        return res;
    }
};