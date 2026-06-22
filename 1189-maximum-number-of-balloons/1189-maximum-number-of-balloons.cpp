class Solution {
public:
    int maxNumberOfBalloons(string text) {

        map<char,int> m;
        int ans=1e9;

        for(auto i:text){
            m[i]++;
        }
        if(!m.count('b') || !m.count('a') || !m.count('l') || !m.count('o') || !m.count('n'))return 0;

        for(auto i:m)
        {
            if(i.first=='b' || i.first=='a' || i.first=='n')
            ans=min(ans,i.second);
            else if(i.first=='l' || i.first=='o')
            ans=min(ans,i.second/2);
        }

        return ans;
        
    }
};