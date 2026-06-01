class Solution {
public:
    int digitFrequencyScore(int n) {

        map<int,int> m;

        while(n>0)
        {
            m[n%10]++;
            n=n/10;
        }

        int ans=0;

        for(auto i:m){
            ans+=(i.first * i.second);
        }

        return ans;
        
    }
};