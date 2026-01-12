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
    TreeNode* replaceValueInTree(TreeNode* root) {

        if(root==nullptr)return nullptr;

      

        queue<TreeNode*> q;
        q.push(root);
        root->val=0;

        while(!q.empty())
        {
            int size=q.size();
            long long sum=0;

            vector<TreeNode*> v;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                v.push_back(node);
                q.pop();

                if(node->left)sum+=node->left->val;
                if(node->right)sum+=node->right->val;
            }

            for(auto i:v)
            {
                long long x=0;
                if(i->left)x+=i->left->val;
                if(i->right)x+=i->right->val;

                if(i->left)
                {
                    i->left->val=sum-x;
                    q.push(i->left);
                }
                if(i->right)
                {
                    i->right->val=sum-x;
                    q.push(i->right);
                }
            }

        }
        

        return root;
    }
};