class Solution {
public:

    int ans=INT_MAX;

    void helper(int i,vector<int> &cookies,int k,vector<int> &v)
    {
        if(i>=cookies.size())
        {
            int maxi=*max_element(v.begin(),v.end());
            ans=min(ans,maxi);
            return;
        }

        for(int j=0;j<k;j++)
        {
            v[j]+=cookies[i];
            helper(i+1,cookies,k,v);
            v[j]-=cookies[i];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {


        vector<int> v(k,0);

        helper(0,cookies,k,v);
        return ans;
    }
};