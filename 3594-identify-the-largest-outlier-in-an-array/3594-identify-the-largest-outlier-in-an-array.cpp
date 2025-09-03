class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {

        map<int,int> m;
        int sum=0;

        int ans=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            m[nums[i]]++;
        }
        cout<<sum;

        sort(nums.begin(),nums.end());

        for(int i=nums.size()-1;i>=0;i--)
        {
            int t=sum-nums[i];
            if(m.find(t/2)!=m.end()&&((t%2)==0)){
                if(t/2==nums[i])
                {
                    if(m[t/2]==1)continue;
                }
                ans=max(ans,nums[i]);
                break;
            }
            
        }

        return ans;
        
    }
};