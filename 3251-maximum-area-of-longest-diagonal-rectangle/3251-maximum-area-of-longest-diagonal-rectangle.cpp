class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        
        int area=0;
        double maxi=0.0;

        priority_queue<pair<double,int>> pq;

        for(int i=0;i<d.size();i++)
        {
            double diag=sqrt((d[i][0]*d[i][0])+(d[i][1]*d[i][1]));
            int a=d[i][0]*d[i][1];

            pq.push({diag,a});
            
        }

        maxi=pq.top().first;

        while(!pq.empty())
        {
            if(pq.top().first==maxi)
            area=max(area,pq.top().second);
            else
            break;

            pq.pop();
        }

        return area;
        
    }
};