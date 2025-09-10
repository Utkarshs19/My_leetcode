class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> free;

        priority_queue<pair<long long int,pair<int,int>>,vector<pair<long long int,pair<int,int>>>,greater<pair<long long int,pair<int,int>>>> busy;


       long long int time=0;

        vector<int> ans;

        for(int i=0;i<servers.size();i++)
        {
            free.push({servers[i],i});
        }

        for(int i=0;i<tasks.size();i++)
        {
            time=max(time,(long long int)i);

            while(!busy.empty()&&busy.top().first<=time )
            {
                pair<int,int> p=busy.top().second;
                free.push(p);
                busy.pop();
            }

            if(free.empty())
            {
                time=busy.top().first;

                while( !busy.empty() && busy.top().first<=time )
                {
                    pair<int,int> p=busy.top().second;
                    free.push(p);
                    busy.pop();
                }

            }

            int x=free.top().first;
            int y=free.top().second;
            ans.push_back(y);

            free.pop();
            busy.push({time+tasks[i],{x,y}});
        }


        return ans;


        
    }
};