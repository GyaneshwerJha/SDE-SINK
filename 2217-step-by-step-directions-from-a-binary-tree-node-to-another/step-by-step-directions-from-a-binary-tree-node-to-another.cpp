class Solution {
public:
    TreeNode *LCA(TreeNode *root, int startValue, int endValue){
        if(root == nullptr || root->val == startValue || root->val == endValue) return root;

        TreeNode *fromLeft = LCA(root->left, startValue, endValue);
        TreeNode *fromRight = LCA(root->right, startValue, endValue);

        if(fromLeft == nullptr) return fromRight;
        if(fromRight == nullptr) return fromLeft;
        return root;
    }

    bool storePath(TreeNode *root, int node, vector<int> &path){
        if(root == nullptr){
            return false;
        }
        path.push_back(root->val);

        if(root->val == node){
            return true;
        }

        if(storePath(root->left, node, path) || storePath(root->right, node, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the LCA of startValue and destValue
        TreeNode *findLCA = LCA(root, startValue, destValue);
        int Baap = findLCA->val;
        
        vector<int> path1;
        vector<int> path2;

        // Store paths from root to startValue and destValue
        storePath(findLCA, startValue, path1);
        storePath(findLCA, destValue, path2);

        string ans = "";
        
        // To move from startValue to LCA, we go up
        for (int i = 1; i < path1.size(); ++i) {
            ans += 'U';
        }

        // To move from LCA to destValue
        for (int i = 1; i < path2.size(); ++i) {
            if (findLCA->left && path2[i] == findLCA->left->val) {
                ans += 'L';
                findLCA = findLCA->left;
            } else if (findLCA->right && path2[i] == findLCA->right->val) {
                ans += 'R';
                findLCA = findLCA->right;
            }
        }

        return ans;
    }
};
