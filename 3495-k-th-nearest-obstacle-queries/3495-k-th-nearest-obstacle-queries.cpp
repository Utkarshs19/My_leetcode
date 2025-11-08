class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {

        vector<int> ans;

        priority_queue<int> pq;

        for(int i=0;i<queries.size();i++)
        {
            pq.push(abs(abs(queries[i][0])+abs(queries[i][1])));
           
            if(pq.size()>k)
            {
                pq.pop();
            }
            if(pq.size()<k)
            ans.push_back(-1);
            else
            ans.push_back(pq.top());
        }

        return ans;
        
    }
};