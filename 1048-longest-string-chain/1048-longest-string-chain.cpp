class Solution {
public:
    map<string,vector<string>> m;
    map<string,bool> m1;
    int x=0;
    map<string,int> m2;

    void bfs(string str)
    {
        queue<string> q;
        q.push(str);
        m1[str]=true;

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string s=q.front();
                q.pop();

                for(int j=0;j<s.length();j++)
                {
                    for(auto k:m[s.substr(0,j)+'*'+s.substr(j)]){
                    if(!m1.count(k))
                    {
                        m1[k]=true;
                        q.push(k);
                    }
                    }
                }
                for(auto k:m[s+'*'])
                {
                    if(!m1.count(k))
                    {
                        m1[k]=true;
                        q.push(k);
                    }
                }
            }
            x++;
        }
    }

    int longestStrChain(vector<string>& words) {

        int ans=0;

        for(int i=0;i<words.size();i++)
        {
            string str=words[i];

            for(int j=0;j<str.length();j++)
            {
                m[str.substr(0,j)+'*'+str.substr(j+1)].push_back(words[i]);
            }

        }

        for(int i=0;i<words.size();i++)
        {
            x=0;
            m1.clear();
            bfs(words[i]);
            ans=max(ans,x);

        }


        return ans;
        
    }
};