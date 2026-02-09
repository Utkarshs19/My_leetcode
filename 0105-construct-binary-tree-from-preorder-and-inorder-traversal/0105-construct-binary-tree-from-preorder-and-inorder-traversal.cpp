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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size()==0)return nullptr;

        TreeNode* head=new TreeNode(preorder[0]);

        int i=0;
        while(inorder[i]!=preorder[0])i++;

        vector<int> il(inorder.begin(),inorder.begin()+i);
        vector<int> ir(inorder.begin()+i+1,inorder.end());

        vector<int> pl(preorder.begin()+1,preorder.begin()+1+il.size());
        vector<int> pr(preorder.begin()+1+il.size(),preorder.end());

        head->left=buildTree(pl,il);
        head->right=buildTree(pr,ir);

        return head;
        
    }
};