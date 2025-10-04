class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> pre(n);

        pre[0]=arr[0];

        int cnt=0;

        if(0==pre[0])cnt++;

        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+arr[i];

            if(i*(i+1)/2 == pre[i])cnt++;

        }

        return cnt;

    }
};