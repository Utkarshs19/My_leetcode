class Solution {
public:
    string alphabetBoardPath(string target) {

        int a=0,b=0;

        map<char,pair<int,int>> m;

        m['a']={0,0};
        m['b']={0,1};
        m['c']={0,2};
        m['d']={0,3};
        m['e']={0,4};

        m['f']={1,0};
        m['g']={1,1};
        m['h']={1,2};
        m['i']={1,3};
        m['j']={1,4};

        m['k']={2,0};
        m['l']={2,1};
        m['m']={2,2};
        m['n']={2,3};
        m['o']={2,4};

        m['p']={3,0};
        m['q']={3,1};
        m['r']={3,2};
        m['s']={3,3};
        m['t']={3,4};

        m['u']={4,0};
        m['v']={4,1};
        m['w']={4,2};
        m['x']={4,3};
        m['y']={4,4};

        m['z']={5,0};

        string ans="";


        for(int i=0;i<target.length();i++)
        {
            int x=m[target[i]].first-a;
            int y=m[target[i]].second-b;

            if(target[i]=='z'){
            for(int i =0;i<abs(y);i++)
            {if(y>0){ans.push_back('R');}else{ans.push_back('L');}}
            for(int i =0;i<abs(x);i++)
            {if(x>0){ans.push_back('D');}else{ans.push_back('U');}}
            }
            else{
        
            if(x>0){
            while(x>0)
            {
                ans+='D';
                x--;
            }
            }
            else
            {
                x=abs(x);
                while(x>0)
                {
                    ans+='U';
                    x--;
                }
            }

            if(y>0){
            while(y>0)
            {
                ans+='R';
                y--;
            }
            }
            else
            {
                y=abs(y);
                while(y>0)
                {
                    ans+='L';
                    y--;
                }
            }
            }

            ans+='!';

           a=m[target[i]].first;
           b=m[target[i]].second;


        }

        return ans;


    }
};