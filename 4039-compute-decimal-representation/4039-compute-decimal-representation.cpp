class Solution {
public:
    vector<int> decimalRepresentation(int n) {

        vector<int> v;

        int k=10;
        int c=0;

        while(n>0)
        {
            int x=n%k;
            if(x!=0)
            v.push_back(x*pow(10,c));

            n=n/k;

            c++;
        }

        reverse(v.begin(),v.end());

        return v;
        
    }
};