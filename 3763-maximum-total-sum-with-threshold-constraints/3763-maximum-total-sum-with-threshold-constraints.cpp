class Solution {
public:
    long long maxSum(vector<int>& nums, vector<int>& threshold) {

        long long ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push({threshold[i],nums[i]});
        }

        int step=1;
        while(!pq.empty())
        {
            int x=pq.top().first;
            int y=pq.top().second;
            pq.pop();

            if(step>=x)
            {
                ans+=y;
            }
            else break;
            step++;
        }

        return ans;
        
    }
};