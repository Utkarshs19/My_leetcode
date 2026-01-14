class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {

        map<pair<int,int>,int> blk;

        long long cnt=1ll*(m-1)*(n-1);

        for(int i=0;i<coordinates.size();i++)
        {
            int x=coordinates[i][0];
            int y=coordinates[i][1];

            if(x-1>=0 && y-1>=0)blk[{x-1,y-1}]++;
            if(x-1>=0 && y+1<n)blk[{x-1,y}]++;
            if(x+1<m && y-1>=0)blk[{x,y-1}]++;
            if(x+1<m && y+1<n)blk[{x,y}]++;
        }

        vector<long long> ans(5,0);
        ans[0]=cnt-blk.size();

        for(auto i:blk)
        {
            ans[i.second]++;
        }

        return ans;

        
    }
};