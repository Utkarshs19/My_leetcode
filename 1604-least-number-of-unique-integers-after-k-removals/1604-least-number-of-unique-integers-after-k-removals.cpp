class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        map<int,int> m;

        for(auto i:arr)
        {
            m[i]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto i:m)
        {
            pq.push({i.second,i.first});
        }

        while(!pq.empty()&&k>0)
        {

            pair<int,int> p;
            p.first=pq.top().first;
            p.second=pq.top().second;
            
            cout<<p.first<<"  "<<p.second<<endl;

            if(p.first<=k){
            k=k-p.first;
            pq.pop();
            }
            else return pq.size();

          


        }

        return pq.size();
        
    }
};