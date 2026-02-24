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
    map<string,int> m;
    string s;

    void dfs(TreeNode* root)
    {
        if(!root)return;

        s+=to_string(root->val);
        dfs(root->left);
        dfs(root->right);

        if(root->left==nullptr && root->right==nullptr)
        {
            m[s]++;
        }
        s.pop_back();

    }

    int sumRootToLeaf(TreeNode* root) {

        dfs(root);

        for(auto i:m)
        {
            string s=i.first;
            int x=i.second;

            reverse(s.begin(),s.end());
            int sum=0;
            for(int j=0;j<s.length();j++)
            {
                if(s[j]=='1')
                {
                    sum+=(pow(2,j));
                }
            }

            ans+=(sum*x);
        }

        return ans;
        
    }
};