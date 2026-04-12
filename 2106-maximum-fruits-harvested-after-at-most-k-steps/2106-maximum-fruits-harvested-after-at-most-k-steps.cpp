class Solution {
public:

    int helper(int left,int right,int start)
    {
        return min(abs(start - left),abs(start - right)) + (right - left);
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {

        int i=0,j=0,sum=0;
        int ans=0;

        while(j<fruits.size())
        {
            sum+=fruits[j][1];
        
            while(i<=j && helper(fruits[i][0],fruits[j][0],startPos)>k)
            {
                sum=sum-fruits[i][1];
                i++;
            }
            ans=max(ans,sum);
            j++;
        }
        return ans;
        
    }
};