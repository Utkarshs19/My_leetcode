class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n=nums.size();
        vector<long long int> pre(n,0);
        vector<long long int> suf(n,0);
        
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];

        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }

        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }

        for(int i=0;i<n;i++)cout<<pre[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)cout<<suf[i]<<" ";

        long long int mini=INT_MAX;
        int idx=0;

        cout<<endl;

        for(int i=0;i<n-1;i++)
        {
            
                mini=min(mini,abs(pre[i]/(i+1)-suf[i+1]/(n-i-1)));
        }

                mini=min(mini,abs(pre[n-1]/n));


        cout<<mini<<endl;
        for(int i=0;i<n-1;i++)
        {
            if(abs(pre[i]/(i+1)-suf[i+1]/(n-i-1))==mini)return i;
        }


        return n-1;
        
    }
};