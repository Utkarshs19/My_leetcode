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

    long long sum=0;

    int SumOfATree(TreeNode *root)
    {
        if(root==nullptr)return 0;
        int sum=0;
        if(root)
        {
            sum+=root->val;
        }
        sum+=SumOfATree(root->left);
        sum+=SumOfATree(root->right);

        return sum;
    }

    long long int pro=1;

    int dfs(TreeNode *root)
    {
        if(!root)return 0;

        long long cur=root->val+dfs(root->left)+dfs(root->right);

        pro=max(pro, cur*(sum-cur));

        return cur;

    }


    int maxProduct(TreeNode* root) {

        
        sum=SumOfATree(root);


        dfs(root);
        

        return pro%1000000007;
    }
};