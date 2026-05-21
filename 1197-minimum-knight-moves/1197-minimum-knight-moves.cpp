class Solution {
public:
    int minKnightMoves(int x, int y) {

        set<pair<int,int>> st;
        queue<pair<int,int>> q;
        x=abs(x);
        y=abs(y);

        q.push({0,0});
        st.insert({0,0});
        int ans=0;

          vector<pair<int,int>> dir = {
            {-2,-1},{-2,1},
            {-1,-2},{-1,2},
            {2,-1},{2,1},
            {1,-2},{1,2}
        };
        
        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                int a=q.front().first;
                int b=q.front().second;
                q.pop();

                if(a==x && b==y)return ans;

                for(auto [dx,dy] : dir)
                {
                    int nx = a + dx;
                    int ny = b + dy;

                    if(nx >= -2 && ny >= -2 &&
                       !st.count({nx,ny}))
                    {
                        st.insert({nx,ny});
                        q.push({nx,ny});
                    }
                }
            }
            ans++;
        }

        return ans;
        
    }
};