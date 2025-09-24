class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {

        int ans=0;

        map<int,vector<int>> m;

        for(int i=0;i<labels.size();i++)
        {
            m[labels[i]].push_back(values[i]);
        }

        priority_queue<int> pq;

        for(auto i:m)
        {
            vector<int> v=i.second;

            sort(v.begin(),v.end());

            int j=v.size()-1;
            int k=useLimit;

            while(j>=0&&k>0)
            {
                pq.push(v[j]);
                j--;
                k--;
            }


        }

        while(!pq.empty()&&numWanted>0)
        {
            ans+=pq.top();
            pq.pop();
            numWanted--;
        }

        return ans;
        
    }
};