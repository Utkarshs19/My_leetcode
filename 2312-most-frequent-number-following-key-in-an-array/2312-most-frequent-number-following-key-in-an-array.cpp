class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {

        map<int,int> m;
        int maxi=INT_MIN;
        int ans;

        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==key)
            {
                m[nums[i+1]]++;

                if(maxi<m[nums[i+1]])
                {
                    maxi=m[nums[i+1]];
                    ans=nums[i+1];
                }
            }
        }
        

        return ans;
    }
};