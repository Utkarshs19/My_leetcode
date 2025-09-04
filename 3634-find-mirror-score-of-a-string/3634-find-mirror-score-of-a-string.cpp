class Solution {
public:
    long long calculateScore(string s) {
        
        map<char,char> m;
        map<char,vector<int>> m1;

        long long ans=0;

        m['a']='z';
        m['b']='y';
        m['c']='x';
        m['d']='w';
        m['e']='v';
        m['f']='u';
        m['g']='t';
        m['h']='s';
        m['i']='r';
        m['j']='q';
        m['k']='p';
        m['l']='o';
        m['m']='n';
        m['n']='m';
        m['o']='l';
        m['p']='k';
        m['q']='j';
        m['r']='i';
        m['s']='h';
        m['t']='g';
        m['u']='f';
        m['v']='e';
        m['w']='d';
        m['x']='c';
        m['y']='b';
        m['z']='a';

        

        for(int i=0;i<s.length();i++)
        {
            m1[s[i]].push_back(i);

            if(m1.find(m[s[i]])!=m1.end())
            {
             
                vector<int> &v=m1[m[s[i]]];

                ans+=(i-v.back());
                v.pop_back();
               vector<int> &v1=m1[s[i]];
               v1.pop_back();
               if(v1.size()==0)
               m1.erase(s[i]);
                if(v.size()==0)
                m1.erase(m[s[i]]);

            }
        }
        
        return ans;
        

    }
};