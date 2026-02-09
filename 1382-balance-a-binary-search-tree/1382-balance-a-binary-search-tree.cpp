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
    vector<int> v;
    void dfs(TreeNode *root)
    {
        if(root==nullptr)return;
        v.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode *helper(vector<int> v,int start,int end)
    {
        if(start>end)return nullptr;
        int mid=start+(end-start)/2;

        TreeNode *head=new TreeNode(v[mid]);
        head->left=helper(v,start,mid-1);
        head->right=helper(v,mid+1,end);
        return head;

    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);

        sort(v.begin(),v.end());
        return helper(v,0,v.size()-1);
    }
};