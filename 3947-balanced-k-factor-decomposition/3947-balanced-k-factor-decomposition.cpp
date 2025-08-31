class Solution {
public:
    int mini=INT_MAX;
    vector<int> ans;

    void helper(int n,int k,vector<int> &temp)
    {
        if(k==1)
        {
            temp.push_back(n);
            vector<int> v=temp;
            sort(v.begin(),v.end());
            int x=v.back()-v[0];
            if(x<mini)
            {
                mini=x;
                ans=temp;
            }
            temp.pop_back();
            return;
        }

        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                temp.push_back(i);
                helper(n/i,k-1,temp);
                temp.pop_back();
                temp.push_back(n/i);
                helper(i,k-1,temp);
                temp.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        
        vector<int> temp;

        helper(n,k,temp);

        return ans;

    }
};