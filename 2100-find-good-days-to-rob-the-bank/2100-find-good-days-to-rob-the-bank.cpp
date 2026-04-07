class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        int n=security.size();

        vector<int> pre(n,0),suf(n,0);

        pre[0]=0;

        for(int i=1;i<n;i++)
        {
            if(security[i]<=security[i-1])
            pre[i]=1+pre[i-1];
            else
            {
                pre[i]=0;
            }
        }

        suf[n-1]=0;

        for(int i=n-2;i>=0;i--)
        {
            if(security[i]<=security[i+1])
            {
                suf[i]=1+suf[i+1];
            }
            else
            {
                suf[i]=0;
            }
        }
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            if(pre[i]>=time && suf[i]>=time)ans.push_back(i);
        }
        return ans;

    }
};