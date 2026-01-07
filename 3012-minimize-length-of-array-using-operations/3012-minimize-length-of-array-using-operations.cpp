class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        
        map<int,int> m;
        for(auto i:nums)m[i]++;

        for(auto i:nums) if(i%m.begin()->first !=0)return 1;

        return (m.begin()->second+1)/2;

    }
};