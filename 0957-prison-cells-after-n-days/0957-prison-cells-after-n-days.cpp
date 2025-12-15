class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {

        n = (n-1) % 14+1;

        vector<int> v(8);

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<7;j++)
            {
                if(cells[j-1]==cells[j+1])
                v[j]=1;
                else v[j]=0;
            }
            v[0]=v[7]=0;
            cells=v;
        }  
        return cells;
    }
};