class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int> ans;

        map<int,vector<int>> m;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                m[i+j].push_back(mat[i][j]);
            }
        }

        bool flag=true;

        for(auto i:m)
        {
            vector<int> v=i.second;

            if(flag==true)
            {
                reverse(v.begin(),v.end());
            }
            flag=!flag;  
            for(int j=0;j<v.size();j++)
            {
                ans.push_back(v[j]);
            }
        }
        return ans;
    }
};