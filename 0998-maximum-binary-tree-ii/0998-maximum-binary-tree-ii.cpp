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
    vector<int> v;
    void dfs(TreeNode* root)
    {
        if(!root)return;

        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* helper(vector<int> &v)
    {
        if(v.size()==0)return nullptr;

        int maxi=INT_MIN;
        int ind=-1;

        for(int i=0;i<v.size();i++)
        {
            if(v[i]>maxi)
            {
                maxi=v[i];
                ind=i;
            }
        }

        TreeNode* ans=new TreeNode(maxi);
        vector<int> v1(v.begin(),v.begin()+ind);
        vector<int> v2(v.begin()+ind+1,v.end());

        ans->left=helper(v1);
        ans->right=helper(v2);

        return ans;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        dfs(root);
        v.push_back(val);

        return helper(v);


    }
};