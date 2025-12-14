class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        map<long long int,int> m;

        int maxi=0;
        int n=wall.size();

        for(int i=0;i<n;i++)
        {
            long long int x=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                x=x+wall[i][j];
                m[x]++;
                maxi=max(m[x],maxi);

            }
        }

        return wall.size()-maxi;
        
    }
};