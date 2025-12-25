class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(),happiness.end());

        long long ans=0;

        int x=0;
        int j=happiness.size()-1;

        while(k>0)
        {
            if(happiness[j]-x<=0)break;
            ans+=(happiness[j]-x);
            x++;
            j--;
            k--;
        }

        return ans;
    }
};