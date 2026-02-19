class Solution {
public:
    int target;
    int cost=INT_MAX;
    int ans;

    void helper(int i,vector<int> &toppingCosts,int sum)
    {
        if(i>=toppingCosts.size())
        {
            if(cost>=abs(target-sum))
            {
                if(cost==abs(target-sum))
                {
                    ans=min(ans,sum);
                    return;
                }
                cost=abs(target-sum);
                ans=sum;
            }
            return;
        }   

        helper(i+1,toppingCosts,sum+toppingCosts[i]);
        helper(i+1,toppingCosts,sum+toppingCosts[i]+toppingCosts[i]);
        helper(i+1,toppingCosts,sum);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        this->target=target;
        
        for(int i=0;i<baseCosts.size();i++)
        {
            helper(0,toppingCosts,baseCosts[i]);    

        }

        return ans;
        
    }
};