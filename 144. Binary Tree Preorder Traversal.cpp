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
    vector<int> preTraversal(TreeNode* root, vector<int>& result)
    {
        if (!root)
            return result;
        result.push_back(root->val);
        preTraversal(root->left, result);
        preTraversal(root->right, result);
        return result;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preTraversal(root, result);
        return result;
    }
};