class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if(nums.size()%k!=0)return false;

        map<int,int> m;
        for(auto i:nums)
        m[i]++;

        while(!m.empty())
        {
            int start=m.begin()->first;

            for(int i=0;i<k;i++)
            {
                if(m.find(start+i)==m.end())return false;

                m[start+i]--;
                if(m[start+i]<=0)m.erase(start+i);
            }

        }

        return true;

        
    }
};