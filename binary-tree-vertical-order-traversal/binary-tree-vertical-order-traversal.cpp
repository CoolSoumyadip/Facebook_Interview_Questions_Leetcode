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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> nodes;
        if(root == NULL)
            return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()) {
            pair<TreeNode*,int> temp = q.front();
            TreeNode *Node = temp.first;
            int x = temp.second;
            q.pop();
            nodes[x].push_back(Node -> val);
            if(Node->left) {
                q.push({Node->left,x-1});
            }
            if(Node -> right) {
                q.push({Node->right,x+1});
            }
            
        }
        
        for(auto p : nodes) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};