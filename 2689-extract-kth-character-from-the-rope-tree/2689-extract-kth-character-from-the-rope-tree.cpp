/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string str;
    void helper(RopeTreeNode* root)
    {
        if(!root)return;

        helper(root->left);
        helper(root->right);

        if(root->val.length()>0)
        {
            str+=root->val;
        }
    }
    char getKthCharacter(RopeTreeNode* root, int k) {
        
        helper(root);

        return str[k-1];
    }
};