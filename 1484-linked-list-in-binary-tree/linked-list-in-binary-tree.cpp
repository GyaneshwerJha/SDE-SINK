class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;  // If we've matched all nodes of the linked list
        if (root == nullptr) return false; // If the tree ended but the linked list still has nodes

        // Check if current nodes match and recurse for the next node in the linked list and left/right child of the tree
        if (root->val == head->val) {
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }

        return false; // If current node values don't match
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;

        // Try to match the linked list starting from the current root node
        // Or recurse for left and right subtree
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
