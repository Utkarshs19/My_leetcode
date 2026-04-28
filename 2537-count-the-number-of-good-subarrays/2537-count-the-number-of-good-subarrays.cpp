class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        long long ans=0;

        int i=0,j=0;

        long long pairs=0;

        map<int,int> m;

        while(j<nums.size())
        {
            pairs+=m[nums[j]];
            m[nums[j]]++;

            while(pairs>=k)
            {
                ans+=(nums.size()-j);

                m[nums[i]]--;
                pairs-=m[nums[i]];
                i++;
            }
            j++;
        }

        return ans;
        
    }
};