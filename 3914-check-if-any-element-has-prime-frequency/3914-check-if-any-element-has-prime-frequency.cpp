class Solution {
public:
    bool check(int num)
    {
        if(num<=1)return false;

        int cnt=0;
        for(int i=1;i<=num;i++)
        {
            if(num%i==0)cnt++;
        }

        if(cnt==2)return true;
        return false;
    }
    bool checkPrimeFrequency(vector<int>& nums) {

        map<int,int> m;

        for(auto i:nums)
        m[i]++;

        for(auto i:m)
        {
            if(check(i.second)==true)return true;
        }

        return false;
        
    }
};