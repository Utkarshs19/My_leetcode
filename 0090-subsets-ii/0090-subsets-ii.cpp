class Solution {
public:
    set<vector<int>> st;
    vector<int> v;
    bool flag=true;
    void perm(int i,vector<int> &v)
    {
        if(i==v.size())
        {
            if(st.count(v))flag=false;
            return;
        }
        for(int j=i;j<v.size();j++)
        {
            swap(v[i],v[j]);
            perm(i+1,v);
            swap(v[i],v[j]);
        }
    }

    void helper(int i,vector<int> &nums,vector<int> &v)
    {
        if(i==nums.size())
        {   
            flag=true;
            perm(0,v);
            if(flag)
            st.insert(v);
            return;
        }

        v.push_back(nums[i]);
        helper(i+1,nums,v);
        v.pop_back();
        helper(i+1,nums,v);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        helper(0,nums,v);

        vector<vector<int>> ans;

        for(auto i:st)
        ans.push_back(i);

        return ans;
        
    }
};
