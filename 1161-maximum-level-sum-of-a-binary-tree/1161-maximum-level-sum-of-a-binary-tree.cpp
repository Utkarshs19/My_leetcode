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
    int maxLevelSum(TreeNode* root) {

        int sum=0;
        int maxi=INT_MIN;
        int level=-1;

        queue<TreeNode*> q;

        q.push(root);
        int k=1;

        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            for(int i=0;i<size;i++)
            {
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                int x=q.front()->val;
                q.pop();

                sum+=x;
            }
            if(maxi<sum)
            {
                maxi=sum;
                level=k;
            }
            k++;
        }


        return level;

        
    }
};