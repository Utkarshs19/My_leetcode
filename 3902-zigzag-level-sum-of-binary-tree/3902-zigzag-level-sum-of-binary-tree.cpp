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
    vector<long long> zigzagLevelSum(TreeNode* root) {

        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);

        bool flag=true;

        while(!q.empty())
        {
            int size=q.size();
            vector<TreeNode*> v;
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                v.push_back(cur);

                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
            if(flag)
            {
                long long sum=0;
                for(int i=0;i<v.size();i++)
                {
                    if(v[i]->left==nullptr)break;
                    sum+=v[i]->val;
                }
                ans.push_back(sum);
            }
            else
            {
                reverse(v.begin(),v.end());
                long long sum=0;
                for(int i=0;i<v.size();i++)
                {
                    if(v[i]->right==nullptr)break;
                    sum+=v[i]->val;
                }
                ans.push_back(sum);
            }
            flag=!flag;
        }
        
        return ans;
    }
};