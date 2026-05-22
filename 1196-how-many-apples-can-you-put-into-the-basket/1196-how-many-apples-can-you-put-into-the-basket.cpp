class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        
        sort(weight.begin(),weight.end());

        int ans=0;
        int sum=0;
        for(int i=0;i<weight.size();i++)
        {
            if(sum+weight[i]<=5000 )
            {
                ans++;
                sum+=weight[i];
            }
        }
        return ans;
    }
};