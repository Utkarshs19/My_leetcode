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
    void inorder(TreeNode* root)
    {
        if(root==NULL)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

        inorder(root);


        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";

        vector<vector<int>> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int key=queries[i];
            int low=0;
            int high=v.size()-1;
            int mid;

        

            while(low<=high)
            {
            mid=low+((high-low)/2);

            if(v[mid]==key)break;
            else if(v[mid]<key)low=mid+1;
            else high=mid-1;
            
            }

            if(v[mid]==key)
            ans.push_back({key,key});
            else
            {
                low=0;
                high=v.size()-1;
                mid=low+(high-low)/2;
            
                if(v[low]>key)
                ans.push_back({-1,v[low]});
                else if(v[high]<key)
                ans.push_back({v[high],-1});
                else
                {
                    
                    if(v[mid]<key)
                    low=mid;
                    else
                    high=mid;

                    for(int i=low;i<=high;i++)
                    {
                        if(v[i]>key)
                        {
                            ans.push_back({v[i-1],v[i]});break;
                        }
                    }
                }

            }

        }   
        return ans;
    }
};