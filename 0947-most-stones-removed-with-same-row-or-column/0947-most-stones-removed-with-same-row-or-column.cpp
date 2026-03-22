class Solution {
public:

    unordered_map<int,vector<pair<int,int>>> m1;
    unordered_map<int,vector<pair<int,int>>> m2;

    set<pair<int,int>> st;

    void dfs(int x,int y)
    {
        st.insert({x,y});

        for(auto [i,j] :m1[x])
        {
            if(!st.count({i,j}))
            dfs(i,j);
        }
        for(auto [i,j] :m2[y])
        {
            if(!st.count({i,j}))
            dfs(i,j);
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        for(int i=0;i<stones.size();i++)
        {
            m1[stones[i][0]].push_back({stones[i][0],stones[i][1]});
            m2[stones[i][1]].push_back({stones[i][0],stones[i][1]});
        }

        int cnt=0;

        for(int i=0;i<stones.size();i++)
        {
            int x=stones[i][0];
            int y=stones[i][1];

            if(!st.count({x,y}))
            {
                cnt++;
                dfs(x,y);
            }
        }

        return stones.size()-cnt;
        
    }
};