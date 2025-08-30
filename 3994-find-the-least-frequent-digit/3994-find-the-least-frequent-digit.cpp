class Solution {
public:
    int getLeastFrequentDigit(int n) {

        map<int,int> m;
        int x=n;

        while(x>0)
        {
            m[x%10]++;
            x=x/10;
        }

        int mini=INT_MAX;

        for(auto i:m)
        mini=min(mini,i.second);

        for(auto i:m)
        {
            if(i.second==mini)return i.first;
        }

        return -1;


        
    }
};