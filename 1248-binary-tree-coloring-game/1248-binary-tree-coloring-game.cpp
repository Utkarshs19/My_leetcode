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

    TreeNode *find(TreeNode* root , int x)
    {
        TreeNode *temp =NULL;

        if(root)
        {
            if(root->val==x)
            temp=root;
            else
            {
                temp=find(root->left,x);
                if(!temp)
                temp=find(root->right,x);
            }
        }

        return temp;
    }

    void count(TreeNode *root ,int &n)
    {
        if(root)
        {
            n++;
            count(root->left,n);
            count(root->right,n);
        }
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {

        int left=0,right=0,parent=0,blue=0;

        TreeNode *temp=find(root,x);
        
        
        count(temp->left,left);
       
        count(temp->right,right);

        blue=max(left,right);

        if(root->val!=x)
        {
            parent=n-(left+right+1);
        }

        blue =max(blue,parent);


        return blue>n-blue;


        
    }
};