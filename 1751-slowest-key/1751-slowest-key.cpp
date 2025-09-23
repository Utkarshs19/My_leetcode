class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {

        int k=0;

        map<char,int> m;
        int maxi=0;

        char ans;

        for(int i=0;i<releaseTimes.size();i++)
        {
            m[keysPressed[i]]=max(releaseTimes[i]-k,m[keysPressed[i]]);
             maxi=max(maxi,m[keysPressed[i]]);

            k=releaseTimes[i];

        }

        for(auto i:m)
        {
            if(i.second==maxi)
            ans= i.first;

            cout<<i.first<<"  "<<i.second<<endl;

        }

        return ans;

        
    }
};