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
    int findMinRight(TreeNode *root){
        int mini = root->val;
        TreeNode *temp = root;
        // cout<<temp->val;
        while(temp->left != nullptr){
            cout<<root->left->val<<" ";
            mini = min(mini,  temp->left->val);
            temp = temp->left;
        }
        // cout<<mini;
        return mini;
    }



    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            if(root->left == nullptr){
                return root->right;
            }
            else if(root->right == nullptr){
                return root->left;
            }
            else{
                int findMin = findMinRight(root->right);
                root->val = findMin;
                root->right = deleteNode(root->right, findMin);
            }
        }

        return root;
    }
};