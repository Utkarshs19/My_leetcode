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
    map<TreeNode*,TreeNode*> m;

    void helper(TreeNode* root)
    {
        if(!root)return;

        if(root->left)
        {
            m[root->left]=root;
            helper(root->left);
        }

        if(root->right)
        {
            m[root->right]=root;
            helper(root->right);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {

        helper(root);
        for(int i=0;i<nodes.size();i++)
        {
            if(nodes[i]==root)return root;
        }
        TreeNode* par=nodes[0];

        for(int i=1;i<nodes.size();i++)
        {
            set<TreeNode*> st;
            TreeNode* cur=nodes[i];
            while(cur)
            {
                st.insert(cur);
                cur=m[cur];
            }
            while(!st.count(par))
            {
                par=m[par];
            }
        }

        return par;
    }
};