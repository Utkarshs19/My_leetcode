class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        map<pair<int,int>,int> m;

        for(int i=0;i<dig.size();i++)
        {
            m[{dig[i][0],dig[i][1]}]++;
        }

        int cnt=0;

        for(int i=0;i<artifacts.size();i++)
        {
            int r1=artifacts[i][0];
            int c1=artifacts[i][1];

            int r2=artifacts[i][2];
            int c2=artifacts[i][3];

            bool flag=true;

            for(int j=r1;j<=r2;j++)
            {
                for(int k=c1;k<=c2;k++)
                {
                    if(m.find({j,k})==m.end())
                    flag=false;
                }
            }
            if(flag==true)cnt++;
        }

        return cnt;
    }
};