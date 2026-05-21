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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {

        queue<TreeNode*> q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();

                if(flag)return cur;

                if(cur==u)flag=true;

                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            if(flag)return nullptr;
        }

        return nullptr;
        
    }
};