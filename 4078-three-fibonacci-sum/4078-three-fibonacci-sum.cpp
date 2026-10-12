class Solution {
public:
    bool threeFibonacciSum(int n) {

        if(n%2==1)return false;
        
        vector<int> v;
        v.push_back(0);
        v.push_back(1);

        while(v.back()<=n/2)
        {
            int m=v.size();
            v.push_back(v[m-1]+v[m-2]);
        }

        int m=v.size();

        return (v[m-2]+v[m-3]+v[m-4]==n);
        
        
        
    }
};