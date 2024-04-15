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
    void findSum(int currSum, int &sum, TreeNode *root){
        if(root->left == NULL && root->right == NULL){
            currSum = currSum * 10 + root->val;
            sum += currSum;
            return;
        }
        
        if(root->left != NULL) {findSum(currSum * 10 + root->val, sum, root->left);}
        if(root->right != NULL) {findSum(currSum * 10 + root->val, sum, root->right);}
        
    }
    int sumNumbers(TreeNode* root) {
        
        int sum = 0;
        int currSum = 0;

        findSum(currSum, sum, root);
        return sum;
    }
};