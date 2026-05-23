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
        map<double,set<int>> m;

        void dfs(TreeNode* root,double target)
        {
            if(!root)return;

            double x=1.0*root->val;

            if(x>=target)
            m[x-target].insert(root->val);
            else
            m[target-x].insert(root->val);

            dfs(root->left,target);
            dfs(root->right,target);
        }

    int closestValue(TreeNode* root, double target) {

        dfs(root,target);

        return *(m.begin()->second).begin();
        
    }
};