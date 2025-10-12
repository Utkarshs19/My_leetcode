class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        
        int sum=0;

        map<int,int> m;

        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;

        for(auto i:m)
        {
            if(i.second%k==0)
            {
                sum+=(i.first * i.second);
            }
        }

        return sum;
        
    }
};