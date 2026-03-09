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
    map<TreeNode*,int> m;

    int helper(TreeNode* root)
    {
        if(!root)return 0;
        if(m.count(root))return m[root];

        int pick=0,take=0;

        pick+=root->val;
        if(root->left)
        {
            pick+=helper(root->left->left);
            pick+=helper(root->left->right);
        }
        if(root->right)
        {
            pick+=helper(root->right->left);
            pick+=helper(root->right->right);
        }

        take=helper(root->left)+helper(root->right);

        return m[root]=max(pick,take);

    }

    int rob(TreeNode* root) {

        return helper(root);
        
    }
};