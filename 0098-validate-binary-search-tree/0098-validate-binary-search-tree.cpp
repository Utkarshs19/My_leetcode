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

    bool helper(TreeNode* root, long long l, long long r)
    {
        if(!root)return true;

        if(root->val<r && root->val>l)
        {
            return helper(root->left,l,root->val) && helper(root->right,root->val,r);
        }
        else
        return false;

    }

    bool isValidBST(TreeNode* root) {

        long long mini=LLONG_MIN;
        long long maxi=LLONG_MAX;

        return helper(root,mini,maxi);
        
    }
};