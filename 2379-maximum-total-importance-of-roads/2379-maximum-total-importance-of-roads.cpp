class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        map<int,int> m;

        for(int i=0;i<roads.size();i++)
        {
            m[roads[i][0]]++;
            m[roads[i][1]]++;
        }

        map<int,int> m1;

        priority_queue<pair<int,int>> pq;

        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }
        int k=n;

        while(!pq.empty())
        {
            m1[pq.top().second]=k;
            k--;
            pq.pop();
        }       


        long long ans=0;

        for(int i=0;i<roads.size();i++)
        {
            ans+=m1[roads[i][0]];
            ans+=m1[roads[i][1]];
        }

        return ans;
    }
};