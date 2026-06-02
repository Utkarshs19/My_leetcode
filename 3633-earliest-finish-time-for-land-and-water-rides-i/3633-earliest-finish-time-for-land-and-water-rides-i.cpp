class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        vector<pair<int,int>> v1,v2;

        for(int i=0;i<landStartTime.size();i++)
        {
            v1.push_back({landStartTime[i],landDuration[i]});
        }

         for(int i=0;i<waterStartTime.size();i++)
        {
            v2.push_back({waterStartTime[i],waterDuration[i]});
        }

        int ans=INT_MAX;

        for(int i=0;i<v1.size();i++)
        {
            int sum;
            sum=v1[i].first+v1[i].second;
            for(int j=0;j<v2.size();j++)
            {
                if(sum<=v2[j].first)
                {
                    ans=min(ans,v2[j].first+v2[j].second);
                }
                if(sum>v2[j].first)
                {
                    ans=min(ans,sum+v2[j].second);
                }
            }
        }

         for(int i=0;i<v2.size();i++)
        {
            int sum=0;
            sum=v2[i].first+v2[i].second;
            for(int j=0;j<v1.size();j++)
            {
                if(sum<=v1[j].first)
                {
                    ans=min(ans,v1[j].first+v1[j].second);
                }
                if(sum>v1[j].first)
                {
                    ans=min(ans,sum+v1[j].second);
                }
            }
        }

        return ans;
        
    }
};