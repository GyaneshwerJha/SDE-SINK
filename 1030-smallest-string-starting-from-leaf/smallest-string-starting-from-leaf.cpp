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
    void solve(string curr, string &result, TreeNode *root){
        if(root->left == nullptr && root->right == nullptr){
            curr = (char)(root->val + 'a') + curr;
            // reverse(curr.begin(), curr.end());
            if(result.empty()){
                result = curr;
            }
            else{
                result = min(result, curr);
            }
            return;
        }

        if(root->left != nullptr){
            solve((char)(root->val + 'a') + curr, result, root->left);
        }
        if(root->right != nullptr){
            solve((char)(root->val + 'a') + curr, result, root->right);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        string curr = "";
        string result = "";

        solve(curr, result, root);
        return result;
    }
};