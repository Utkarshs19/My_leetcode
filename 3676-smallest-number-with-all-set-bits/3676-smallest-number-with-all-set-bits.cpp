class Solution {
public:
    int smallestNumber(int n) {

        vector<int> v;

        int k=0;
        int ans=0;

        while(n>0)
        {
            ans=ans+pow(2,k);
            n=n/2;
            k++;
        }
        
        
        // for(int i=0;i<v.size();i++)
        // {
        //     v[i]=1;

        //     cout<<v[i]<<" ";

        //     ans=ans+pow(2,k);
        //     k++;
        // }

        return ans;

        
    }
};