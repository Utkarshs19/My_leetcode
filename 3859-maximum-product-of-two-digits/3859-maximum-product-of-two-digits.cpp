class Solution {
public:
    int maxProduct(int n) {

        int m1=-1e9;
        int m2=-1e9;
        vector<int> v;
        while(n>0)
        {
            v.push_back(n%10);
            n=n/10;
        }
        sort(v.begin(),v.end());

        return (long long)v[v.size()-1]*v[v.size()-2];
        
    }
};