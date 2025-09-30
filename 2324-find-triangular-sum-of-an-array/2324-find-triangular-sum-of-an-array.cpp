class Solution {
public:
    int triangularSum(vector<int>& nums) {

        vector<int> v;

        int n=nums.size();
        while(true){
            vector<int> v;
            if(nums.size()==1)return nums[0];
            for(int i=1;i<n;i++)
            {
                v.push_back((nums[i-1]+nums[i])%10);
            }

            nums.clear();

            for(int i=0;i<v.size();i++)nums.push_back(v[i]);

            v.clear();

            n--;

        }
        
        return nums[0];
    }
};