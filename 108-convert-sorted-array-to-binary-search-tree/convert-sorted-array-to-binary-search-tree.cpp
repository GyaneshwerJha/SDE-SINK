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
    TreeNode *BST(int low, int high, vector<int> &nums){
        if(low > high){
            return nullptr;
        }

        int mid = (low + high) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = BST(low, mid - 1, nums);
        node->right = BST(mid + 1, high, nums);
        return node;
    }

    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(0, nums.size() - 1, nums);    
    }
};