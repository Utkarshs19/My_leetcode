class Solution {
public:
    int X;
    int helper(int i,int j,vector<int> nums)
    {

        map<int,int> m;

        for(int a=i;a<j;a++)
        {
            m[nums[a]]++;
        }
        if(m.size()<X)
        return accumulate(nums.begin()+i,nums.begin()+j,0);

        priority_queue<pair<int,int>> pq;

        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }

        int b=X;

        int sum=0;

        while(b>0 && !pq.empty())
        {
            sum+=(pq.top().first * pq.top().second);
            pq.pop();
            b--;
        }

        return sum;

    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        X=x;

        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n-k+1;i++)
        {
            ans.push_back(helper(i,i+k,nums));
        }
        

        return ans;
    }
};