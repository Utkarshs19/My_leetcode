class Solution {
public:

    bool check(vector<int> &nums,int val,int threshold)
    {
        int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            int a=nums[i]/val;
            int b=nums[i]%val;

            sum+=a;
            if(b>0)sum++;
        }

        return sum<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int high=*max_element(nums.begin(),nums.end());
        int low=1;

        int ans;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(check(nums,mid,threshold))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};