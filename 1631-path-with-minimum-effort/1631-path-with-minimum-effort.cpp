class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int ans=0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; 

        

        int n=heights.size();
        int m=heights[0].size();

        set<string> vis;

        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            int effort=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;


            pq.pop();

            ans=max(ans,effort);
            
            if(i==n-1 && j==m-1)return ans;

            vis.insert(to_string(i)+","+to_string(j));

            if(i-1>=0 && vis.find(to_string(i-1)+","+to_string(j))==vis.end())
            {
                    pq.push({abs(heights[i-1][j]-heights[i][j]),{i-1,j}});
            }

            if(i+1<n && vis.find(to_string(i+1)+","+to_string(j))==vis.end())
            {
                pq.push({abs(heights[i+1][j]-heights[i][j]),{i+1,j}});
            }

            if(j-1>=0 && vis.find(to_string(i)+","+to_string(j-1))==vis.end())
            {
                pq.push({abs(heights[i][j-1]-heights[i][j]),{i,j-1}});
            }

            if(j+1<m && vis.find(to_string(i)+","+to_string(j+1))==vis.end())
            {
                pq.push({abs(heights[i][j+1]-heights[i][j]),{i,j+1}});
            }
        }

        return ans;
        
    }
};