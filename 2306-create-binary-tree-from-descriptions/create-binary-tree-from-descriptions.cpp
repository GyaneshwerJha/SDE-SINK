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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n = desc.size();
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> storeChild;

        for(auto it : desc){
            int parent = it[0];
            int child = it[1];
            int type = it[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(type == 1){
                mp[parent] -> left = mp[child];
            }
            else{
                mp[parent] -> right = mp[child];
            }

            storeChild.insert(child);
        }

        int findRoot = -1;
        for(auto it : desc){
            int parent = it[0];
            if(storeChild.find(parent) == storeChild.end()){
                findRoot = it[0];
                break;
            }
        }

        return mp[findRoot];
    }
};