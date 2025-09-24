class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {

        priority_queue<int> pq;

        map<int,int> m;

        for(int i=0;i<x.size();i++)
        {
            if(m.find(x[i])!=m.end())
            {
               int z=m[x[i]];

               m[x[i]]=max(z,y[i]);
            }
            else
            {
                m[x[i]]=y[i];
            }
        }

        for(auto i:m)
        {
            pq.push(i.second);
        }
        if(pq.size()<3)return -1;

        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        int c=pq.top();pq.pop(); 

        return a+b+c;
    }
};