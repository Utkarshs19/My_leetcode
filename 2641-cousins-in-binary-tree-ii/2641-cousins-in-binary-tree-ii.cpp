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

        vector<vector<int>> v;

        queue<TreeNode*> q;
        q.push(root);
        v.push_back({root->val});

        while(!q.empty())
        {
            int size=q.size();
            vector<int> a;
            
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front();
                q.pop();

                if(node->left && node->right)
                {
                    a.push_back(node->left->val+node->right->val);
                }
                else if(node->left && node->right==nullptr)
                {
                    a.push_back(node->left->val);
                }
                else if(node->right && node->left==nullptr)
                {
                    a.push_back(node->right->val);
                }

                if(node->left)
                q.push(node->left);

                if(node->right)
                q.push(node->right);
                
            }
            v.push_back(a);
        }

        
        
        q.push(root);
        root->val=0;
        int k=1;

        if(v.size()==1)return root;

        while(!q.empty())
        {
            int size=q.size();

            int sum=accumulate(v[k].begin(),v[k].end(),0);

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left && node->right)
                {
                    int x=node->left->val+node->right->val;
                    node->left->val=sum-x;
                    node->right->val=sum-x;
                }
                else if(node->left && node->right==nullptr)
                {
                    node->left->val=sum-node->left->val;
                }
                else if(node->right && node->left==nullptr)
                {
                    node->right->val=sum-node->right->val;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            k++;
        }



        return root;
    }
};