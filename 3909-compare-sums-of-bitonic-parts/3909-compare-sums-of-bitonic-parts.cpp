class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

        int idx;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                idx=i;
            }
        }

        long long sum1=accumulate(nums.begin(),nums.begin()+idx+1,0ll);
        long long sum2=accumulate(nums.begin()+idx,nums.end(),0ll);

        if(sum1==sum2)return -1;
        else if(sum1>sum2)return 0;
        else return 1;
        
    }
};