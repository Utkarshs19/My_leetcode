class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {


        int i=0,j=0;

        int ans=INT_MIN;

        multiset<int> m;

        while(j<nums.size())
        {
            m.insert(nums[j]);

            

            while((*m.rbegin()-*m.begin())>limit  && i<j)
            {
                auto it=m.find(nums[i]);

                m.erase(it);

               

                i++;

            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
        
    }
};