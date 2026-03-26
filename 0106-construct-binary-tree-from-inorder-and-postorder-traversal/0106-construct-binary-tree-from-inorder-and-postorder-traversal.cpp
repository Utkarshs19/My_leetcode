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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(postorder.size()==0)return nullptr;
        int len=postorder.size();
        TreeNode* ans=new TreeNode(postorder[len-1]);

        int ind=-1;

        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==postorder[len-1])ind=i;
        }
        vector<int> in1(inorder.begin(),inorder.begin()+ind);
        vector<int> post1(postorder.begin(),postorder.begin()+ind);
        vector<int> in2(inorder.begin()+ind+1,inorder.end());
        vector<int> post2(postorder.begin()+ind,postorder.end()-1);

        ans->left=buildTree(in1,post1);
        ans->right=buildTree(in2,post2);

        return ans;
        
    }
};