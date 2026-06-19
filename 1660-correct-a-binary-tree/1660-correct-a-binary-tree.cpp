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
    map<TreeNode*,pair<TreeNode*,bool>> m;

    void helper(TreeNode* root)
    {
        if(!root)return;

        if(root->left)
        {
            m[root->left]={root,true};
            helper(root->left);
        }
        if(root->right)
        {
            m[root->right]={root,false};
            helper(root->right);
        }
    }
    TreeNode* correctBinaryTree(TreeNode* root) {

        helper(root);

        queue<TreeNode*> q;
        q.push(root);
        set<TreeNode*> st;
        TreeNode* fromNode=nullptr;
        TreeNode* toNode=nullptr;
        bool flag=false;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();

                if(cur->left)
                {
                    st.insert(cur->left);
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    if(st.count(cur->right))
                    {
                        fromNode=cur;
                        toNode=cur->right;
                        flag=true;
                        break;
                    }
                    st.insert(cur->right);
                    q.push(cur->right);
                }
            }
            if(flag)break;
        }

        TreeNode* par=m[fromNode].first;
        bool f=m[fromNode].second;

        if(f)
        {
            par->left=nullptr;
        }
        else
        par->right=nullptr;


        return root;

        

    }
};