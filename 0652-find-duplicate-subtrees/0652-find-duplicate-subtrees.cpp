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
    vector<TreeNode*> ans;
    map<string, int> m;

    string dfs(TreeNode* root)
    {
        if(!root)return "";

        string left=dfs(root->left);
        string right=dfs(root->right);

        string str=to_string(root->val);
        str+='+';
        str+=left;
        str+='+';
        str+=right;

        m[str]++;
        if(m[str]==2)ans.push_back(root);

        return str;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        dfs(root);

        return ans;
    }
};