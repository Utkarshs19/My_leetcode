class Solution {
public:
    int totalDistance(string s) {

        map<char,pair<int,int>> m;

        m['q']={0,0};
        m['w']={0,1};
        m['e']={0,2};
        m['r']={0,3};
        m['t']={0,4};
        m['y']={0,5};
        m['u']={0,6};
        m['i']={0,7};
        m['o']={0,8};
        m['p']={0,9};
        m['a']={1,0};
        m['s']={1,1};
        m['d']={1,2};
        m['f']={1,3};
        m['g']={1,4};
        m['h']={1,5};
        m['j']={1,6};
        m['k']={1,7};
        m['l']={1,8};
        m['z']={2,0};
        m['x']={2,1};
        m['c']={2,2};
        m['v']={2,3};
        m['b']={2,4};
        m['n']={2,5};
        m['m']={2,6};


        int ans=abs(m[s[0]].first-m['a'].first) +    abs( m[s[0]].second-m['a'].second);

        for(int i=1;i<s.length();i++)
        {
            ans+=(abs(m[s[i]].first-m[s[i-1]].first) + abs(m[s[i]].second-m[s[i-1]].second));
        }
        
        return ans;
    }
};