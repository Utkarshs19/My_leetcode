class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {

        vector<long long> ans;

        map<int,long long> m;

        priority_queue<pair<long long,int>> pq;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]+=freq[i];

            pq.push({m[nums[i]],nums[i]});

            while(!pq.empty()&&m[pq.top().second]!=pq.top().first)pq.pop();

            ans.push_back(pq.top().first);

        }
        return ans;
    }
};