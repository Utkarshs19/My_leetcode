class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        map<string,bool> m1;
        map<string,vector<string>> m;
        m1[startGene]=false;
        m1[endGene]=false;
        for(int i=0;i<bank.size();i++)
        {
            string str=bank[i];
            m1[str]=false;

            for(int j=0;j<str.length();j++)
            {
                string s;
                s+=str.substr(0,j);
                s+="$";
                s+=str.substr(j+1);

                m[s].push_back(str);
            }
        }
        int ans=0;

        queue<string> q;
        q.push(startGene);
        m1[startGene]=true;

        while(!q.empty())
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                string s=q.front();
                q.pop();
                if(s==endGene)return ans;

                for(int j=0;j<s.length();j++)
                {
                    string a=s.substr(0,j);
                    a+="$";
                    a+=s.substr(j+1);

                    for(auto k:m[a])
                    {
                        if(m1[k]==false)
                        {
                        m1[k]=true;
                         q.push(k);
                        }
                    }
                }

            }
            ans++;

        }

        return -1;
        
    }
};