class Solution {
public:
    int smallestNumber(int n) {

        vector<int> v;

        while(n>0)
        {
            v.push_back(n%2);
            n=n/2;
        }
        
        int k=0;
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            v[i]=1;

            cout<<v[i]<<" ";

            ans=ans+pow(2,k);
            k++;
        }

        return ans;

        
    }
};