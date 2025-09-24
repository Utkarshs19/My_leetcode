class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {

        vector<int> ans;


        for(int i=0;i<queries.size();i++)
        {
priority_queue<pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>> pq;

        int x=queries[i][0];
        int y=queries[i][1];

        for(int j=0;j<nums.size();j++)
        {
            string s=nums[j];
            reverse(s.begin(),s.end());
            s=s.substr(0,y);

            reverse(s.begin(),s.end());

            pq.push({s,j});
        }

        while(!pq.empty()&&x-1>0)
        {
            pq.pop();
            x--;
        }

        ans.push_back(pq.top().second);

        }
        
        return ans;
    }
};