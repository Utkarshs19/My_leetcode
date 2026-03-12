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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        if(nums.size()==0)return nullptr;

        int maxi=INT_MIN;
        int ind=-1;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                ind=i;
            }
        }

        TreeNode* ans=new TreeNode(maxi);
        vector<int> v1(nums.begin(),nums.begin()+ind);
        ans->left=constructMaximumBinaryTree(v1);
        vector<int> v2(nums.begin()+ind+1,nums.end());
        ans->right=constructMaximumBinaryTree(v2);

        return ans;
        
    }
};