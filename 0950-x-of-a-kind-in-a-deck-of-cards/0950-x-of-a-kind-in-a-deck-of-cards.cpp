class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        map<int,int> m;
        int mini=INT_MAX;

        for(int i=0;i<deck.size();i++){
        m[deck[i]]++;
        
        }

        for(auto i:m)
        mini=min(mini,i.second);

        if(mini==1)return false;

        bool ans=false;

    for(int j=2;j<=mini;j++)
    {
        int cnt=0;
        for(auto i:m)
        {
            if(i.second%j==0 )cnt++;
        }
        if(cnt==m.size())return true;
    
    }

        return false;

        
        
    }
};