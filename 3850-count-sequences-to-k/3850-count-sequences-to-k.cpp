class Solution {
public:

    map<tuple<int,long long,long long>,int> m;

    int helper(int i,vector<int> &nums,long long k,long long num,long long deno)
    {
        if(i>=nums.size())
        {
            long double ans=(long double)num/(long double)deno;
            if(ans==k)return 1;

            return 0;
        }

        if(m.count({i,num,deno}))return m[{i,num,deno}];

        int x1=helper(i+1,nums,k,num*nums[i],deno);
        int x2=helper(i+1,nums,k,num,deno*nums[i]);
        int x3=helper(i+1,nums,k,num,deno);

        return m[{i,num,deno}]=x1+x2+x3;
    }

    int countSequences(vector<int>& nums, long long k) {

        return helper(0,nums,k,1,1);
        
    }
};