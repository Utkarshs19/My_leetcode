class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int i=0,j=0;
        int cur=0;
        int n=arr.size();

        int ans=INT_MAX;

        vector<int> minlentilli(n,INT_MAX);
        int mini=INT_MAX;
        while(j<n)
        {
            cur+=arr[j];
            while(cur>target)
            {
                cur=cur-arr[i];
                i++;
            }

            if(cur==target)
            {
                int len=j-i+1;

                if(i>0 && minlentilli[i-1]!=INT_MAX)
                {
                    ans=min(ans,len+minlentilli[i-1]);
                }
                mini=min(mini,len);
            }
             minlentilli[j]=mini;
            j++;
        }

        return ans==INT_MAX?-1:ans;
    }
};