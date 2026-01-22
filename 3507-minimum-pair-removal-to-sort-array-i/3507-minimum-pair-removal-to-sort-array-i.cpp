class Solution {
public:

    bool nonsorted(vector<int> &nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {

        int cnt=0;

        while(!nonsorted(nums))
        {
            int mini=INT_MAX;
            for(int i=1;i<nums.size();i++)
            {
                mini=min(mini,nums[i]+nums[i-1]);
            }

            int idx;
            vector<int> temp;

            for(int i=1;i<nums.size();i++)
            {
                if(mini==nums[i]+nums[i-1])
                {
                    idx=i-1;
                    break;
                }
            }

            for(int i=0;i<nums.size();i++)
            {
                if(idx==i)
                {
                    temp.push_back(mini);
                    i++;
                }
                else
                temp.push_back(nums[i]);
            }

            nums=temp;
            cnt++;

        }
        

        return cnt;
    }
};