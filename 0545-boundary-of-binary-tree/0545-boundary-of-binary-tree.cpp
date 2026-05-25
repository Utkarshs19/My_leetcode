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
    stack<int> st;
    vector<int> ans;
    bool isLeaf(TreeNode* cur)
    {
        return (cur->left==nullptr && cur->right==nullptr);
    }
    void dfs1(TreeNode* root)
    {
        TreeNode* cur=root->left;
        while(cur)
        {
            if(!isLeaf(cur))ans.push_back(cur->val);
            if(cur->left)
            {
                cur=cur->left;
            }
            else
            cur=cur->right;
        }    
    }
    
    void dfs2(TreeNode* root)
    {
        if(!root)
        return;

        dfs2(root->left);
        if(root->left==nullptr && root->right==nullptr)ans.push_back(root->val);
        dfs2(root->right);
    }

    void dfs3(TreeNode* root)
    {
        TreeNode* cur=root->right;
        while(cur)
        {
            if(!isLeaf(cur))
            st.push(cur->val);
            if(cur->right)cur=cur->right;
            else
            cur=cur->left;
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        if(!root)return ans;
        if(!isLeaf(root))ans.push_back(root->val);
        dfs1(root);
        dfs2(root);
        dfs3(root);

        return ans;

    }
};