class Solution {
public:
    vector<int> price;
    unordered_map<string,int> dp;
    string getkey(vector<int> &needs)
    {
        string str;
        for(int j=0;j<needs.size();j++)
        {
            str+=to_string(needs[j]);
            str+='*';
        }
        return str;
    }
    int helper(vector<vector<int>> &special,vector<int> needs)
    {
        string key=getkey(needs);

        if(dp.count(key))return dp[key];

        int ans=0;
        for(int j=0;j<needs.size();j++)
        {
            ans+=(needs[j]*price[j]);
        }

        for(auto &offer:special)
        {
            vector<int> v=needs;
            bool flag=true;
            for(int j=0;j<v.size();j++)
            {
                if(v[j]<offer[j]){
                    flag=false;
                    break;
                }
                v[j]-=offer[j];
            }
            if(flag)
            {
                ans=min(ans,offer.back()+helper(special,v));
            }
        }

        return dp[key]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

    this->price=price;

    return helper(special,needs);

        
    }
};