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
    int k;
    map<TreeNode*, TreeNode*> m;
    TreeNode* node=nullptr;
    set<TreeNode*> st;
    void helper(TreeNode* root)
    {
        if(!root)return;

        if(root->val==k)
        {
            node=root;
        }

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
    int findClosestLeaf(TreeNode* root, int k) {
        
        this->k=k;
        helper(root);

        queue<TreeNode*> q;

        q.push(node);
        st.insert(node);

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();

                if(cur->left==nullptr && cur->right==nullptr)return cur->val;

                if(m.count(cur) && !st.count(m[cur]))
                {
                    q.push(m[cur]);
                    st.insert(m[cur]);
                }
                if(cur->left && !st.count(cur->left))
                {
                    q.push(cur->left);
                    st.insert(cur->left);
                }

                if(cur->right && !st.count(cur->right))
                {
                    q.push(cur->right);
                    st.insert(cur->right);
                }
            }
        }

        return -1;

    }
};