class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n=nums.size();
        vector<int> v(n,0);

        for(int i=0;i<requests.size();i++)
        {
            v[requests[i][0]]+=1;
            if(requests[i][1]+1<n)
            v[requests[i][1]+1]-=1;
        }
        for(int i=1;i<n;i++)
        {
            v[i]+=v[i-1];
        }
        priority_queue<long long> pq;
        for(int i=0;i<v.size();i++)
        {
            pq.push(v[i]);
        }

        sort(nums.begin(),nums.end());
        n=nums.size()-1;
        long long ans=0;

        while(!pq.empty())
        {
            ans=(ans+(1ll*pq.top()*nums[n])%1000000007)%1000000007;
            n--;
            pq.pop();
        }

        return ans;
    }
};