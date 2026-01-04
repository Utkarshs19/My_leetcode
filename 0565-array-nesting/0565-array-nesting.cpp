class Solution {
public:
    set<int> st;
    int ans=0;
    int n;

    void dfs(int i,vector<int> &vis,vector<int> &nums )
    {
        if(i>=n)return;

        st.insert(nums[i]);
        vis[i]=1;
        
        if(vis[nums[i]]==-1)
        dfs(nums[i],vis,nums);
        else
        return;

    }

    int arrayNesting(vector<int>& nums) {

        n=nums.size();
        vector<int> vis(n,-1);

        for(int i=0;i<nums.size();i++)
        {
            st.clear();
            if(vis[i]==-1)
            dfs(i,vis,nums);
            
            ans=max(ans,int(st.size()));
        }
        
        return ans;
    }
};