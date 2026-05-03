class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        vector<int> v1,v2;

        for(int i=0;i<values.size();i++)
        {
            v1.push_back(values[i]+i);
            v2.push_back(values[i]-i);
        }

        for(int i=1;i<v1.size();i++)
        {
            v1[i]=max(v1[i],v1[i-1]);
        }
        for(int i=v2.size()-2;i>=0;i--)
        {
            v2[i]=max(v2[i],v2[i+1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<v1.size();i++)
        {
            if(i+1<v1.size())
            {
                ans=max(ans,v1[i]+v2[i+1]);
            }
        }

        return ans;
        
    }
};