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

    set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;

        if(st.count(k - root->val)) return true;
        st.insert(root->val);
        bool fromLeft = findTarget(root->left, k);
        bool fromRight = findTarget(root->right, k);

        return fromLeft || fromRight;
    }
};