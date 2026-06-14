class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        int n=nums.size();
        vector<long long> first;

        int i=0,j=0;
        long long sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1==firstLen)
            {
                first.push_back(sum);
                sum=sum-nums[i];
                i++;
            }
            j++;
        }

        for(int i=0;i<first.size();i++)
        {
            cout<<first[i]<<endl;
        }
        
        long long ans=0;
        for(int i=0;i<first.size();i++)
        {   
            long long maxi=0;
            if(i>=secondLen)
            {
                long long s=0;
                int a=0,b=0;
                while(b<i)
                {
                    s+=nums[b];
                    if(b-a+1==secondLen)
                    {
                        maxi=max(maxi,s);
                        s=s-nums[a];
                        a++;
                    }
                    b++;
                }
            }
            if(n-i-firstLen>=secondLen)
            {
                int a=i+firstLen;
                int b=i+firstLen;
                long long s=0;
                while(b<n)
                {
                    s+=nums[b];
                    if(b-a+1==secondLen)
                    {
                        maxi=max(maxi,s);
                        s=s-nums[a];
                        a++;
                    }
                    b++;
                }
            }
            ans=max(ans,first[i]+maxi);
        }   

        return ans;
        
    }
};