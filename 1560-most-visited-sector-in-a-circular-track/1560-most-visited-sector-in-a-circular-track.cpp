class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {

        map<int,int> m;
        m[rounds[0]]++;

        for(int i=1;i<rounds.size();i++)
        {
            int x=rounds[i-1];
            int y=rounds[i];
            if(x==n)x=1;
            else
            x=x+1;
            if(y<x)
            {
                int j=x;
                while(j<=n)
                {
                    m[j]++;
                    j++;
                }
                j=1;
                while(j<=y)
                {
                    m[j]++;
                    j++;
                }
            }
            else
            {
                while(x<=y)
                {
                    m[x]++;
                    x++;
                }
            }

        }
        int maxi=0;
        for(auto i:m)
        {
            maxi=max(maxi,i.second);
        }
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second==maxi)ans.push_back(i.first);
        }

        return ans;
        
    }
};