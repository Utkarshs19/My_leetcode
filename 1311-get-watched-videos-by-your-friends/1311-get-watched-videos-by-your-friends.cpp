class Solution {
public:

    set<int> v;

    void bfs(int id,int level,map<int,vector<int>> &m,int l)
    {
        int n=m.size();
        queue<int> q;
        q.push(id);
        vector<bool> vis(n,false);
        vis[id]=true;

        while(!q.empty())
        {
            if(level==l)
            {
                while(!q.empty())
                {
                    v.insert(q.front());
                    q.pop();
                }
                break;
            }
            int size=q.size();
            
            l++;
            while(size>0){
                int x=q.front();
                
                q.pop();
                for(auto i:m[x])
                {
                    if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                    }
                }
            size--;
            }
        }
        return;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

        map<int,vector<int>> m;

        for(int i=0;i<friends.size();i++)
        {
            for(int j=0;j<friends[i].size();j++)
            {
                m[i].push_back(friends[i][j]);
            }
        }
            
            bfs(id,level,m,0);

        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;

        map<string,int> m1;



        for(auto i:v)
        {
           vector<string> a=watchedVideos[i];

            for(int j=0;j<a.size();j++)
            {
                m1[a[j]]++;
            }
        }

        for(auto i:m1)
        {
            pq.push({i.second,i.first});
        }


        vector<string> ans;

        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};