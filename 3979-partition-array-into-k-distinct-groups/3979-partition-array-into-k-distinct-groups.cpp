class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        map<int,int> m;

        if(nums.size()%k!=0)return false;

        int count=nums.size()/k;


        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        for(auto i:m)
        {
            if(i.second>count)return false;
        }

        if(m.size()<k)return false;

        return true;


        
    }
};