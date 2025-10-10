class Solution {
public:
    int minOperations(vector<int>& nums) {

        int x=1;

        int cnt=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=x)
            {
                nums[i]=x;
                if(x==0)x=1;
                else x=0;

                cnt++;
            }
        }

        return cnt;
        
    }
};