class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        set<int> s;
        for(auto i:nums)
        {
            s.insert(i);
        }

        int x=1;

        while(true)
        {
            if(s.count(x*k))
            {
                x++;
            }
            else
            return x*k;
        }

        return x*k;
        
    }
};