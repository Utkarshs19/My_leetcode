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
    map<int,int> par;
    map<int,TreeNode*> m;

    string str;

    bool dfs(TreeNode* root, int s)
    {
        if (root == nullptr) return false;

        if (root->val == s) return true;

        if (root->left)
        {
            str.push_back('L');
            if (dfs(root->left, s)) return true;
            str.pop_back();
        }

        if (root->right)
        {
            str.push_back('R');
            if (dfs(root->right, s)) return true;
            str.pop_back();
        }

        return false;
    }

    void parent(TreeNode* root)
    {
        if(root==nullptr)return;

        m[root->val]=root;
        if(root->left)
        {
            par[root->left->val]=root->val;
            parent(root->left);
        }
        if(root->right)
        {
            par[root->right->val]=root->val;
            parent(root->right);
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {

        par[root->val]=-1;
        parent(root);

        vector<int> v1,v2;
        set<int> st;

        int x=startValue;
        while(x!=-1)
        {
            st.insert(x);
            x=par[x];
        }

        x=destValue;
        while(x!=-1)
        {
            v2.push_back(x);
            x=par[x];
        }

        for(auto i:par)
        {
            cout<<i.first<<"  "<<i.second<<endl;
        }
        
        int lca;

        for(int i=0;i<v2.size();i++)
        {
            if(st.count(v2[i]))
            {
                lca=v2[i];
                break;
            }
        }

        cout<<lca<<endl;

        string s1,s2;
        str="";
        dfs(m[lca],startValue);
        s1=str;
        str="";
        dfs(m[lca],destValue);
        s2=str;

        string ans;

        for(int i=0;i<s1.length();i++)
        {
            ans+='U';
        }

        ans+=s2;


        return ans;

    }
};