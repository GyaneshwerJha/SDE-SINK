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
    TreeNode* postOrder(TreeNode *root, set<int> &st, vector<TreeNode*> &ans){
        if(root == nullptr) return root;

        root->left = postOrder(root->left, st, ans);
        root->right = postOrder(root->right, st, ans);

        // check if it is present in set
        if(st.find(root->val) != st.end()){
            if(root->left != nullptr){
                ans.push_back(root->left);
            }
            if(root->right != nullptr){
                ans.push_back(root->right);
            }
            return NULL;
        }
        else{
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        
        postOrder(root, st, ans);
        if(st.find(root->val) == st.end()){
            ans.push_back(root);
        }
        return ans;
    }
};