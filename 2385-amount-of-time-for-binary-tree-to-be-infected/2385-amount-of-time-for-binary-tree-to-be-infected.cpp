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

    unordered_map<TreeNode*,vector<TreeNode*> > m;
    unordered_map<int,bool> m1;

    queue<TreeNode*> q;

    int start;
    
    void dfs(TreeNode* root)
    {
        if(!root)return;

        if(root->val==start)q.push(root);

        if(root->left)
        {   
            m[root].push_back(root->left);
            m[root->left].push_back(root);
        }
        if(root->right)
        {
            m[root].push_back(root->right);
            m[root->right].push_back(root);
        }

        m1[root->val]=false;

        dfs(root->left);
        dfs(root->right);

    }

    int amountOfTime(TreeNode* root, int start) {

        if(!root)return 0;
        this->start=start;

        dfs(root);

        int ans=0;
        m1[start]=true;

        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();

                for(auto j:m[cur])
                {
                    if(m1[j->val]==false)
                    {
                        m1[j->val]=true;
                        q.push(j);
                    }
                }
            }
            ans++;
        }

        
        return ans-1;
        
    }
};