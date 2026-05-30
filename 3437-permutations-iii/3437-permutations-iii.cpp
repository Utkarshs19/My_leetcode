class Solution {
public:
    set<vector<int>> st;

    void helper(int i,vector<int> &v)
    {
        if(i==v.size())
        {
            for(int j=1;j<v.size();j++)
            {
                if(v[j]%2==0 && v[j-1]%2==0)return;
                if(v[j]%2==1 && v[j-1]%2==1)return;  
            }
            st.insert(v);
            return;
        }

        for(int j=i;j<v.size();j++)
        {
            swap(v[i],v[j]);
            helper(i+1,v);
            swap(v[i],v[j]);
        }
    }

    vector<vector<int>> permute(int n) {

        vector<int> v;
        for(int i=1;i<=n;i++)v.push_back(i);

        helper(0,v);

        vector<vector<int>> ans;

        for(auto i:st)ans.push_back(i);

        return ans;

    }
};