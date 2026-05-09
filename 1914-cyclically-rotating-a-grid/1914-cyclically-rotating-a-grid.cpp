class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        vector<vector<int>> v;
        int n=grid.size();
        int m=grid[0].size();
        int top=0,bottom=n-1;
        int left=0,right=m-1;


        while(top<=bottom && left<=right)
        {
            vector<int> l;
            int i=left;
            for(i;i<=right;i++)
            l.push_back(grid[top][i]);
            top++;
            
            i=top;
            for(i;i<=bottom;i++)
            {
                l.push_back(grid[i][right]);
            }

            right--;
            i=right;
            for(i;i>=left;i--)
            {
                l.push_back(grid[bottom][i]);
            }

            bottom--;
            i=bottom;
            for(i;i>=top;i--)
            {
                l.push_back(grid[i][left]);
            }
            left++;

            int x=k%l.size();
            vector<int> a(l.begin()+x,l.end());
            for(int j=0;j<x;j++)
            {
                a.push_back(l[j]);
            }

            v.push_back(a);
        }

        top=0,bottom=n-1,left=0,right=m-1;

        int a=0,b=0;

        while(top<=bottom && left<=right)
        {
            int i=left;
            b=0;
            for(i;i<=right;i++)
            {
                grid[top][i]=v[a][b];
                b++;
            }
            top++;
            i=top;
            for(i;i<=bottom;i++)
            {
                grid[i][right]=v[a][b];
                b++;
            }
            right--;
            i=right;
            for(i;i>=left;i--)
            {
                grid[bottom][i]=v[a][b];
                b++;
            }
            bottom--;
            i=bottom;
            for(i;i>=top;i--)
            {
                grid[i][left]=v[a][b];
                b++;
            }
            left++;

            a++;

        }
        
        return grid;
    }
};