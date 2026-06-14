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
    int ans=0;

    bool dfs(TreeNode* root,TreeNode* par)
    {
        if(!root)return true;

        bool isLeft=dfs(root->left,root);
        bool isRight=dfs(root->right,root);

        if(isLeft && isRight)
        {
            ans++;

            if(par!=nullptr)
            {
                return par->val==root->val;
            }
            return true;
        }
        return false;


    }

    int countUnivalSubtrees(TreeNode* root) {

        dfs(root,nullptr);

        return ans;
        
    }
};