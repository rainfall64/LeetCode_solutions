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
void dfs(TreeNode* root, vector<int>& result)
{
    if(!root)
        return;
    if(root->left && !root->right)
        result.push_back(root->left->val);
    if(!root->left && root->right)
        result.push_back(root->right->val);
    dfs(root->left, result);
    dfs(root->right, result);
        
}
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};