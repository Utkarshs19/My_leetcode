class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {

        int mini=INT_MAX;

        int ans=-1;

        for(int i=0;i<capacity.size();i++)
        {
            if(capacity[i]>=itemSize)
            {
                if(mini>capacity[i])
                {
                    mini=capacity[i];
                    ans=i;
                }
            }
        }

        return ans;
        
    }
};