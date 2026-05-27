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
    map<int,int> m1;

    void dfs(TreeNode* root)
    {
        if(!root)return;

        if(root->left)m[root->left->val]=root->val;
        if(root->right)m[root->right->val]=root->val;

        dfs(root->left);
        dfs(root->right);
    }
    int findDistance(TreeNode* root, int p, int q) {

     m[root->val]=-1;
     dfs(root);
    
    int k=0;
    set<int> st;

        while(p!=-1)
        {
            st.insert(p);
            m1[p]=k;
            k++;
            p=m[p];

        }

        int cnt=0;

        while(q!=-1)
        {
            if(st.count(q))
            {
                return cnt+m1[q];
            }
            cnt++;
            q=m[q];
        }
     
        return 0;
    }
};