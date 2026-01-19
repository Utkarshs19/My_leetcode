class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        set<string> st;
        for(int i=0;i<deadends.size();i++)
        {
            st.insert(deadends[i]);
        }

        map<string,bool> m;
        m["0000"]=true;
        queue<string> q;
        q.push("0000");

        int ans=0;

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                string s=q.front();
                q.pop();

                if(st.count(s))continue;

                if(s==target)return ans;

                for(int j=0;j<4;j++)
                {
                    if(s[j]=='9')s[j]='0';
                    else s[j]=s[j]+1;

                    if(!m.count(s))
                    {
                        m[s]=true;
                        q.push(s);
                    }
                    if(s[j]=='0')s[j]='9';
                    else s[j]=s[j]-1;

                    if(s[j]=='0')s[j]='9';
                    else s[j]=s[j]-1;

                    if(!m.count(s))
                    {
                        m[s]=true;
                        q.push(s);
                    }

                    if(s[j]=='9')s[j]='0';
                    else s[j]=s[j]+1;


                }

            }
            ans++;
        }
        

        return -1;
    }
};