class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        

        long long sum=accumulate(nums.begin(),nums.end(),0LL);


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }

        vector<long long> ans;

        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];

            if(nums[x]>0)
            sum=sum-nums[x];
            nums[x]=-1;

            while(!pq.empty()&&y>0)
            {
                if(nums[pq.top().second]==-1){
                pq.pop();continue;
                }
                else
                {
                    sum=sum-pq.top().first;
                    nums[pq.top().second]=-1;
                    pq.pop();
                    y--;
                }


            }

            ans.push_back(sum);

        }


        return ans;

    }
};