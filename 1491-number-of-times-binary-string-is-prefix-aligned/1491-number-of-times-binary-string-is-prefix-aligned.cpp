class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {

        int maxi=INT_MIN;
        int cnt=0;

        int ans=0;

        for(int i=0;i<flips.size();i++)
        {
            maxi=max(maxi,flips[i]);
            cnt++;

            if(cnt==maxi)ans++;

        }

        return ans;
        
    }
};