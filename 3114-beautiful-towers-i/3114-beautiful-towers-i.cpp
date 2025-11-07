class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {

        long long ans=0;

        int x=INT_MAX,y=INT_MAX;

        for(int i=0;i<heights.size();i++)
        {
            long long int sum=heights[i];
            x=heights[i];
            y=heights[i];

            for(int j=i-1;j>=0;j--)
            {
                x=min(heights[j],x);
                sum+=x;
            }

            for(int j=i+1;j<heights.size();j++)
            {
                y=min(y,heights[j]);
                sum+=y;
            }

            ans=max(ans,sum);
        }

        return ans;
        
    }
};