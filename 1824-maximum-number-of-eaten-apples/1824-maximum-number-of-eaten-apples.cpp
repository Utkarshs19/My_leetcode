class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {

        int ans=0;

        int n=apples.size();

        int i=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        while(i<n||(!pq.empty()))
        {
            if(i<n && apples[i]>0)
            pq.push({(i+days[i]-1),apples[i]});

            while(!pq.empty()&&pq.top().first<i)
            pq.pop();

            if(!pq.empty())
            {
                pair<int,int> p=pq.top();
                pq.pop();
                if(p.second>1)
                pq.push({p.first,p.second-1});

                ans++;
            }
            i++;
        }

        return ans;
        
    }
};