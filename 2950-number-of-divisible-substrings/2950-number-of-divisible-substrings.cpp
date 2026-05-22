class Solution {
public:
    int countDivisibleSubstrings(string word) {

        int ans=0;

        map<char,int> m;

        m['a']=1;       m['k']=4;           m['u']=8;
        m['b']=1;       m['l']=5;           m['v']=8;
        m['c']=2;       m['m']=5;           m['w']=8;
        m['d']=2;       m['n']=5;           m['x']=9;
        m['e']=2;       m['o']=6;           m['y']=9;
        m['f']=3;       m['p']=6;           m['z']=9;
        m['g']=3;       m['q']=6;
        m['h']=3;       m['r']=7;
        m['i']=4;       m['s']=7;
        m['j']=4;       m['t']=7;

        for(int i=0;i<word.length();i++)
        {
            int sum=0;
            for(int j=i;j<word.length();j++)
            {
                sum+=m[word[j]];

                if(sum%(int)(j-i+1)==0)ans++;
            }
        }
        return ans;
    }
};