class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        vector<int> maxi;
        vector<int> mini;

        maxi.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            maxi.push_back(max(maxi.back(),nums[i]));
        }

        mini.resize(nums.size());
        mini[nums.size()-1]=nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--)
        {
            mini[i]=min(mini[i+1],nums[i]);
        }

        for(int i=0;i<nums.size();i++)
        {
            if(maxi[i]-mini[i]<=k)return i;
        }
        return -1;
        
    }
};