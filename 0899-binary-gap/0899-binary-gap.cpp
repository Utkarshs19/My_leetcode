class Solution {
public:
    int binaryGap(int n) {

        vector<int> v;
        int k=0;

        while(n>0)
        {
            if(n%2==1)
            v.push_back(k);
            n=n/2;
            k++;
        }
        

        int ans=0;

        for(int i=1;i<v.size();i++)
        {
            ans=max(ans,v[i]-v[i-1]);
        }

        return ans;

        
    }
};