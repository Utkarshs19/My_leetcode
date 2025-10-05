class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false));

        vector<vector<bool>> atl(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            pac[i][0]=true;
            atl[i][m-1]=true;
        }

        for(int i=0;i<m;i++)
        {
            pac[0][i]=true;
            atl[n-1][i]=true;
        }


        bool flag=true;

        while(flag)
        {
            flag=false;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(!pac[i][j])
                    {
                        if(i>0 && pac[i-1][j] && heights[i][j]>=heights[i-1][j])
                        {
                            pac[i][j]=true;
                            flag=true;
                        }
                        else if(i<n-1 && pac[i+1][j] && heights[i][j]>=heights[i+1][j])
                        {
                            pac[i][j]=true;
                            flag=true;
                        }
                        else if(j>0 && pac[i][j-1] && heights[i][j]>=heights[i][j-1])
                        {
                            pac[i][j]=true;
                            flag=true;
                        }
                        else if(j<m-1 && pac[i][j+1] && heights[i][j]>=heights[i][j+1])
                        {
                            pac[i][j]=true;
                            flag=true;
                        }
                    }


                    if(!atl[i][j])
                    {
                        if(i>0 && atl[i-1][j] && heights[i][j]>=heights[i-1][j])
                        {
                            atl[i][j]=true;
                            flag=true;
                        }
                        else if(i<n-1 && atl[i+1][j] && heights[i][j]>=heights[i+1][j])
                        {
                            atl[i][j]=true;
                            flag=true;
                        }
                        else if(j>0 && atl[i][j-1] && heights[i][j]>=heights[i][j-1])
                        {
                            atl[i][j]=true;
                            flag=true;
                        }
                        else if(j<m-1 && atl[i][j+1] && heights[i][j]>=heights[i][j+1])
                        {
                            atl[i][j]=true;
                            flag=true;
                        }
                    }
                }


            }

        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
        
    }
};