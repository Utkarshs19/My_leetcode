class Solution {
public:
    string getSmallestString(int n, int k) {

        string ans(n,'a');

        k=k-n;

        for(int i=n-1;i>=0&&k;i--)
        {
            int x=min(k,25);
            ans[i]+=x;
            k=k-x;
        }

        return ans;
        
    }
};