class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        vector<vector<int>> v;
        
        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    vector<int> temp;
                    int k1=i,k2=j;

                    while(k1<n&&k2<n)
                    {
                        temp.push_back(grid[k1][k2]);
                        k1++;
                        k2++;
                    }
                    v.push_back(temp);
                }
            }
        }

        int x=v.size()/2;

        cout<<x;
        
        for(int i=0;i<v.size();i++)
        {
            sort(v[i].begin(),v[i].end());
            if(i==0)reverse(v[i].begin(),v[i].end());
            if(i>x)
            reverse(v[i].begin(),v[i].end());
        }
        vector<int> abc;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                abc.push_back(v[i][j]);
            }
        }

        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    int k1=i,k2=j;

                    while(k1<n&&k2<n)
                    {
                        grid[k1][k2]=abc[k];
                        k1++;
                        k2++;
                        k++;
                    }
                    
                }
            }
        }




        return grid;

    }
};