class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        vector<int> v;

        v.push_back(startTime[0]-0);

        for(int i=1;i<endTime.size();i++)
        {
            v.push_back(startTime[i]-endTime[i-1]);
        }

        v.push_back(eventTime-endTime[endTime.size()-1]);

        int ans=0;
      
        int n=v.size();

        vector<int> left(n),right(n);

        left[0]=v[0];
        right[n-1]=v[n-1];

        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],v[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],v[i]);
        }
 
        for(int i=0;i<startTime.size();i++)
        {
            
            int x=endTime[i]-startTime[i];
            int gap=0;
            if(i>0)
            gap=max(gap,left[i-1]);
            if(i+2<=startTime.size())
            gap=max(gap,right[i+2]);

            if(gap>=x)
            {
                ans=max(ans,v[i]+v[i+1]+x);
            }
            else
            ans=max(ans,v[i]+v[i+1]);

        }

        return ans;
        
    }
};