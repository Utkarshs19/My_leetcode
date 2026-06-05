class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int cnt=0,cnt1=0;

        for(auto i:s)
        {
            if(i=='1')cnt++;
            else
            {
                cnt1++;
                cnt1=min(cnt1,cnt);
            }
        }

        return cnt1;
        
    }
};