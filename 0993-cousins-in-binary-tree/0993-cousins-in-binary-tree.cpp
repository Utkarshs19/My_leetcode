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
    bool isCousins(TreeNode* root, int x, int y) {

        queue<pair<TreeNode*,int>> q;
        q.push({root,-1});

        bool flag1=false;
        bool flag2=false;
        int par1,par2;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                int par=q.front().second;
                q.pop();

                if(node->val==x)
                {
                    flag1=true;
                    par1=par;
                }
                if(node->val==y)
                {
                    flag2=true;
                    par2=par;
                }

                if(node->left)
                {
                    q.push({node->left,node->val});
                }

                if(node->right)
                {
                    q.push({node->right,node->val});
                }
            }

            if((flag1 && !flag2)||(!flag1 && flag2))return false;
            if(flag1 && flag2 && par1==par2)return false;
        }
        
        return true;
    }
};