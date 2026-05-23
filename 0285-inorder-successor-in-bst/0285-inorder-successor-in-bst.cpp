/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> v;

    void dfs(TreeNode* root)
    {
        if(!root)return;

        dfs(root->left);
        v.push_back(root);
        dfs(root->right);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        dfs(root);


        for(int i=0;i<v.size();i++)
        {
            if(v[i]==p)
            {
                if(i+1<v.size())return v[i+1];
                else
                return nullptr;
            }
        }

        return nullptr;
        
    }
};