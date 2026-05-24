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
    map<int,vector<pair<int,int>>> m;
    void dfs(TreeNode* root,int sum,int level)
    {
        if(!root)return;

        m[sum].push_back({root->val,level});

        if(root->left)
        {
            dfs(root->left,sum-1,level+1);
        }
        if(root->right)
        {
            dfs(root->right,sum+1,level+1);
        }

    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        dfs(root,0,0);

        vector<vector<int>> ans;

        for(auto i:m)
        {
            vector<pair<int,int>> v=i.second;
            sort(v.begin(),v.end(),[](auto &a,auto &b){
                return a.second<b.second;
            });
            vector<int> v1;
            for(int j=0;j<v.size();j++)v1.push_back(v[j].first);
            ans.push_back(v1);
        }
        return ans;

    }
};