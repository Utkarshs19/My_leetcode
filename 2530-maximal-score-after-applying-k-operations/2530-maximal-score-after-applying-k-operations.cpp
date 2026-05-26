class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        long long ans=0;

        priority_queue<int> pq;

        for(auto i:nums)pq.push(i);


        while(k>0)
        {
            ans+=pq.top();
            int x=pq.top();
            pq.pop();
            if(x%3==0)x=x/3;
            else
            {
                x=x/3;
                x++;
            }
            pq.push(x);
            k--;
        }
        return ans;
        
    }
};