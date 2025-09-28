class Solution {
public:
    long long splitArray(vector<int>& nums) {

        int n=nums.size();

        vector<bool> leftValid(n);
        vector<bool> rightValid(n);

        vector<long long> pre(n);
        vector<long long> suf(n);

        pre[0]=nums[0];
        leftValid[0]=true;

        suf[n-1]=nums[n-1];
        rightValid[n-1]=true;


        for(int i=1;i<n;i++)
        {
            if(leftValid[i-1] && nums[i]>nums[i-1])
            leftValid[i]=true;
            else
            leftValid[i]=false;

            pre[i]=pre[i-1]+nums[i];

        }


        for(int i=n-2;i>=0;i--)
        {
            if(rightValid[i+1] && nums[i]>nums[i+1])
            rightValid[i]=true;
            else
            rightValid[i]=false;

            suf[i]=suf[i+1]+nums[i];
        }
        

        long long mini=LLONG_MAX;

        for(int i=0;i<=n-2;i++)
        {
            
            if(leftValid[i] && rightValid[i+1])
            {
                mini=min(mini,abs(pre[i]-suf[i+1]));
            }
        }


        return mini==LLONG_MAX?-1:mini;

        
    }
};