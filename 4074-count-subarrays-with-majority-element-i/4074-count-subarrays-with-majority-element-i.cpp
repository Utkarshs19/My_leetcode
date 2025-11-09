class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {


        int ans=0;
        map<int,int> m;

        for(int i=0;i<nums.size();i++)
        {   
            m[target]=0;
            for(int j=i;j<nums.size();j++)
            {
                if(target==nums[j])
                m[target]++;

                if(m[target]>(j-i+1)/2)
                ans++;
            }
        }
        
        return ans;
    }
};