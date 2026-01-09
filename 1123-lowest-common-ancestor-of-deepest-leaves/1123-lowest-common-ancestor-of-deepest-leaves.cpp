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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;

        if(root==nullptr)return root;
        m[root]=nullptr;
        q.push(root);

        vector<TreeNode*> v;

        while(!q.empty())
        {
            int size=q.size();
            v.clear();

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node);

                if(node->left)
                {
                    m[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    m[node->right]=node;
                    q.push(node->right);
                }
            }

        }

        set<TreeNode*> st(v.begin(),v.end());

        while(st.size()>1)
        {
            set<TreeNode*> s;

            for(auto i:st)
            {
                s.insert(m[i]);
            }
            st=s;
        }

        return *st.begin();

        
    }
};