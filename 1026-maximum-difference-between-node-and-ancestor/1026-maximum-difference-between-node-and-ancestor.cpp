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
    int ans=-1;

    void dfs(TreeNode* root, int maxi, int mini)
    {
        if(root==nullptr)return;

        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        int x=max(abs(maxi-root->val),abs(mini-root->val));
        ans=max(ans,x);

        dfs(root->left,maxi,mini);
        dfs(root->right,maxi,mini);
    }

    int maxAncestorDiff(TreeNode* root) {

        if(root==nullptr)return 0;

        int maxi=-1e9,mini=1e9;

        dfs(root,maxi,mini);

        return ans;
        
    }
};