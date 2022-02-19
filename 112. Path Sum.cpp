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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<TreeNode*, int> temp = q.front();
                q.pop();
                if (!temp.first->left && !temp.first->right)
                {
                    if (temp.second == targetSum)
                        return true;                    
                }
                if (temp.first->left)
                {
                    q.push({temp.first->left, temp.second + temp.first->left->val});
                }
                if (temp.first->right)
                {
                    q.push({temp.first->right, temp.second + temp.first->right->val});
                }
            }
        }
        return false;
    }
};