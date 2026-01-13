class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double> v(1,poured);

        for(int i=0;i<=query_row;i++)
        {
            vector<double> next(i+2,0);
            for(int j=0;j<=i;j++)
            {
                if(v[j]>=1)
                {
                    next[j]+=(v[j]-1)/2.0;
                    next[j+1]+=(v[j]-1)/2.0;
                    v[j]=1;
                }
            }
            if(i!=query_row)
            v=next;
        }

        return v[query_glass];
        
    }
};