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

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode *> m;
        unordered_map<int,int> parents,child;

        for(int i=0;i<descriptions.size();i++)
        {
            if(m.find(descriptions[i][0])==m.end())
            {
                TreeNode *cur=new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]]=cur;
            }

            if(m.find(descriptions[i][1])==m.end())
            {
                TreeNode *cur=new TreeNode(descriptions[i][1]);
                m[descriptions[i][1]]=cur;
            }

            if(descriptions[i][2])
            {
                m[descriptions[i][0]]->left=m[descriptions[i][1]];
            }
            else
            {
                m[descriptions[i][0]]->right=m[descriptions[i][1]];
            }

            parents[descriptions[i][0]]++;
            child[descriptions[i][1]]++;

        }

        for(auto i:m)
        {
            if(parents[i.first]>0&&child[i.first]==0)
            return i.second;
        }

        return nullptr;
    }
};