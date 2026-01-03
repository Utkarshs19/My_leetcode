class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        map<string,vector<string>> m;

        map<string,bool> m1;
        m1[beginWord]=false;
        m1[endWord]=false;

        for(int i=0;i<wordList.size();i++)
        {
            string str=wordList[i];
            for(int j=0;j<str.length();j++)
            {
                m[str.substr(0,j)+'*'+str.substr(j+1)].push_back(str);
            }
            m1[str]=false;
        }

        queue<string> q;
        q.push(beginWord);
        m1[beginWord]=true;
        int cnt=0;

        for(auto i:m)
        {
            cout<<i.first<<"--->";
            for(int j=0;j<i.second.size();j++)
            {
                cout<<i.second[j]<<" ";
            }
            cout<<endl;
        }

        while(!q.empty())
        {
            int size=q.size();



            for(int j=0;j<size;j++)
            {
                string str=q.front();
                q.pop();

                if(str==endWord)return cnt+1;

                for(int k=0;k<str.length();k++)
                {
                    string s=str.substr(0,k);
                    s+='*';
                    s+=str.substr(k+1);

                    for(auto a:m[s])
                    {
                        if(m1[a]==false)
                        {
                            m1[a]=true;
                            q.push(a);
                        }
                    }

                }
            }
            cnt++;

        }

        

        return 0;
    }
};