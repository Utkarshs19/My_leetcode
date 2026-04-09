class Solution {
public:
    long long minimumSteps(string s) {
        
        long long ans=0,cnt=0;

        int j=s.length()-1;

        while(j>=0)
        {
            if(s[j]=='0')cnt++;
            else
            {
                ans+=cnt;
            }
            j--;
        }
        return ans;


    }
};