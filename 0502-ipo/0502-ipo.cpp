class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        for(int i=0;i<profits.size();i++)
        {
            minHeap.push({capital[i],profits[i]});
        }

        while(k>0)
        {
            while(!minHeap.empty() && minHeap.top().first<=w)
            {
                maxHeap.push({minHeap.top().second,minHeap.top().first});
                minHeap.pop();
            }

            w+=maxHeap.top().first;

            maxHeap.pop();
            k--;
        }

        return w;

    }
};