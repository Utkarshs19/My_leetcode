class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {

        vector<long long> ans;

        if(finalSum%2==1)return {};

        long long int k=2;

        ans.push_back(k);
        long long diff = finalSum-k;
        long long sum=0;
        sum+=2;
        k+=2;

        while(true)
        {
            if(sum==finalSum)return ans;
            if(k<=diff)
            {
                sum+=k;
                diff=finalSum-sum;
                
                ans.push_back(k);
            }
            else
            {
                int x=ans[ans.size()-1];
                ans.pop_back();
                sum=sum-x;
                sum+=k;
                ans.push_back(k);
                diff=finalSum-sum;
            }
            k+=2;
        }

        return ans;
        
    }
};