class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {

        long long ans=0;
        priority_queue<vector<int>> pq;
        for(int i=0;i<technique1.size();i++)
        {
            pq.push({technique1[i]-technique2[i],technique1[i],technique2[i]});
        }

        while(!pq.empty())
        {
            if(k>0){
            ans+=pq.top()[1];
            k--;
            }
            else
            {
                ans+=max(pq.top()[1],pq.top()[2]);
            }
            pq.pop();
        }

        

        return ans;
        
    }
};