class Solution {
public:
    int maximumLength(vector<int>& nums) {

        map<long long ,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        long long ans=1;
        if(m.count(1))
        {
            if(m[1]%2==0)
            {
                ans=max(ans,(long long)(m[1]-1));
            }
            else
            {
                ans=max(ans,(long long)(m[1]));
            }
            m.erase(1);
        }

        for(auto i:m)
        {
            long long x=i.first;
            long long len=0;
            while(m.count(x) && m[x]>1)
            {
                len+=2;
                if(x>1e9)break;
                x=x*x;
            }
            if(m.count(x))len++;
            else len--;
            
            ans=max(ans,len);
        }
        return ans;

        
    }
};