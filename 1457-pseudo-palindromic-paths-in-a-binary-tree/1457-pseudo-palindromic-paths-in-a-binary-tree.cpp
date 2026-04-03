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

    map<int,int> m;
    int ans=0;

    void dfs(TreeNode* root)
    {
        if(!root)return;

        m[root->val]++;
        dfs(root->left);
        dfs(root->right);

        if(root->left==nullptr && root->right==nullptr)
        {
            int cnt=0;
            for(auto i:m)
            {
                if(i.second%2==1)cnt++;
            }
            if(cnt<=1)ans++;
        }
        m[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};