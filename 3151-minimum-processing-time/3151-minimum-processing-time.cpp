class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        long long ans=0;
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        reverse(tasks.begin(),tasks.end());
        int k=0;

        for(int i=0;i<processorTime.size();i++)
        {
            int x=max({tasks[k],tasks[k+1],tasks[k+2],tasks[k+3]});
            k=k+4;

            ans=max(ans,(long long)processorTime[i]+x);

        }

        return ans;
    }
};