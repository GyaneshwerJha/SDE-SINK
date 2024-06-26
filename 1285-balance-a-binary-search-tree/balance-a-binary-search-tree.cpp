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
    vector<int> store;
    void inorder(TreeNode *root){
        if(root == nullptr) return;

        inorder(root->left);
        store.push_back(root->val);
        inorder(root->right);
    }

    TreeNode *newBalanceBST(int start, int end){
        if(start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(store[mid]);
        node->left = newBalanceBST(start, mid - 1);
        node->right = newBalanceBST(mid + 1, end);
        return node;
    }
    

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return newBalanceBST(0, store.size() - 1);
    }
};