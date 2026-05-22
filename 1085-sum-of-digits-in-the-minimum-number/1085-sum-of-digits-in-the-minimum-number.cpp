class Solution {
public:
    int sumOfDigits(vector<int>& nums) {

        int mini=1e9;
        for(auto i:nums)mini=min(mini,i);
        int sum=0;
        while(mini>0)
        {
            sum+=(mini%10);
            mini=mini/10;
        }

        return sum%2==0?1:0;
        
    }
};