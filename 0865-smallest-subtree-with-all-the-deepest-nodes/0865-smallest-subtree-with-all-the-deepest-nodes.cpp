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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if(root==nullptr)return root;

        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        m[root]=nullptr;

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

        unordered_set<TreeNode*> st(v.begin(),v.end());

        while(st.size()>1)
        {
            unordered_set<TreeNode*> next;
            for(auto i:st)
            {
                next.insert(m[i]);
            }
            st=next;
        }

        return *st.begin();
        
    }
};