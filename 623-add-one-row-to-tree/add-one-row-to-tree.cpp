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
    void addRow(int currDepth, TreeNode *root, int val, int depth){
        if(currDepth == depth - 1){
            TreeNode *currNode1 = new TreeNode(val);
            TreeNode *currNode2 = new TreeNode(val);

            if(root->left != nullptr){
                currNode1->left = root->left;
            }
            if(root->right != nullptr){
                currNode2->right = root->right;
            }

            root->left = currNode1;
            root->right = currNode2;
            return;
        }

        if(root->left != nullptr){
            addRow(currDepth + 1, root->left, val, depth);
        }
        if(root->right != nullptr){
            addRow(currDepth + 1, root->right, val, depth);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == nullptr) return root;
        if(depth == 1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        int currDepth = 1;
        addRow(currDepth, root, val, depth);
        return root;
    }
};