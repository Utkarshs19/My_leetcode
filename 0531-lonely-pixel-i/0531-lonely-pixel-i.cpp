class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {

        int n=picture.size();
        int m=picture[0].size();

        vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>(m,{-1,-1})); 

        for(int i=0;i<n;i++)
        {   
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(picture[i][j]=='B')cnt++;
            }
            for(int j=0;j<m;j++)
            {
                v[i][j].first=cnt;
            }
        }

        for(int i=0;i<m;i++)
        {   
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(picture[j][i]=='B')cnt++;
            }

            for(int j=0;j<n;j++)
            {
                v[j][i].second=cnt;
            }
        }
        
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j].first==1 && v[i][j].second==1 && picture[i][j]=='B')ans++;
            }
        }

        return ans;
    }
};