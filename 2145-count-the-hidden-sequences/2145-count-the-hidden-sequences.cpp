class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n=differences.size();
        vector<long long> pre;
        pre.push_back(differences[0]);
        for(int i=1;i<n;i++)
        {
            pre.push_back(pre.back()+differences[i]);
        }

        long long min=*min_element(pre.begin(),pre.end());
        long long max=*max_element(pre.begin(),pre.end());

        int ans=0;
        for(int i=lower;i<=upper;i++)
        {
            if(i+min>=lower && i+max<=upper)ans++;
        }

        return ans;

        
    }
};