class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {

        set<pair<int,int>> st;

        for(int i=0;i<circles.size();i++)
        {
            int x=circles[i][0];
            int y=circles[i][1];

            int r=circles[i][2];

            int a=x-r;
            int b=y-r;

            int c=x+r;
            int d=y+r;

            cout<<a<<"  "<<b<<endl;
            cout<<c<<"  "<<d<<endl;

            for(int p=a;p<=c;p++)
            {
                for(int q=b;q<=d;q++)
                {
                    if(sqrt(((p-x)*(p-x))+((q-y)*(q-y)))<=r)
                    st.insert({p,q});
                }
            }


        }
        
        return st.size();
    }
};