class Solution {
public:
    vector<int> ans;
    int maxi=INT_MIN;
    vector<int> v;

    void helper(int i,int sum,int numArrows,vector<int>& aliceArrows)
    {
        if(i<0)
        {
            if(sum>=maxi)
            {
                maxi=sum;
                ans=v;
                ans[0]+=numArrows;
            }

            return;
        }

        int x=aliceArrows[i];
        if(numArrows>x)
        {
            v[i]=x+1;
            helper(i-1,sum+i,numArrows-x-1,aliceArrows);
            v[i]=0;
            helper(i-1,sum,numArrows,aliceArrows);
        }
        else
        {
            helper(i-1,sum,numArrows,aliceArrows);
        }
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
       v.resize(12,0);

        helper(11,0,numArrows,aliceArrows);

        return ans;
    }
};