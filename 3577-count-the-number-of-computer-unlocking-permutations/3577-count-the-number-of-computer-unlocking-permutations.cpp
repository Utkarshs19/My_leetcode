class Solution {
public:
    int countPermutations(vector<int>& complexity) {

        int cnt=0;

        for(int i=0;i<complexity.size();i++)
        {
            if(complexity[i]==complexity[0])cnt++;
        }

        int mini=*min_element(complexity.begin(),complexity.end());

        if(mini!=complexity[0])return 0;

        if(cnt>1)return 0;

        int n=complexity.size();
        n--;
        long long ans=1;
        while(n>0)
        {
            ans=(ans*n)%1000000007;
            n--;
        }
        
        return ans;
    }
};