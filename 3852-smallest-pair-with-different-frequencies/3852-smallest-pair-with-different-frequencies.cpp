class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        vector<int> v(101,0);
    
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]++;
        }

        for(int i=1;i<=100;i++)
        {
            if(v[i]>0)
            {
                int cnt=v[i];
                for(int j=i+1;j<=100;j++)
                {
                    if(v[j]==0)continue;
                    if(v[j]!=cnt)
                    {
                        return {i,j};
                    }
                }
            }
        }
        return {-1,-1};
    }
};