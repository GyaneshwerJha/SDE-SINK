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
    int mSum = INT_MIN;
    int maxSum(TreeNode *root){
        if(root == NULL) return 0;

        int fromLeft = maxSum(root->left);
        if(fromLeft < 0) fromLeft = 0;
        int fromRight = maxSum(root->right);
        if(fromRight < 0) fromRight = 0;
        mSum = max(mSum, fromLeft + fromRight + root->val);
        return root->val + max(fromLeft, fromRight);
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        maxSum(root);
        return mSum;
    }
};