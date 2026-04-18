class Solution {
public:

    map<char,int> m;
    map<char,int> sc;
    int ans=0;

    void helper(int i,vector<string>& words,int sum)
    {
        if(i==words.size())
        {
            ans=max(ans,sum);

            return ;
        }

        map<char,int> m1;
        bool flag=true;

        for(int j=0;j<words[i].length();j++)
        {
            m1[words[i][j]]++;
        }

        for(auto i:m1)
        {
            m[i.first]-=i.second;
        }

        for(auto i:m)
        {
            if(i.second<0)flag=false;
        }

        if(flag)
        {
            for(auto i:m1)
            {
                sum+=(i.second*sc[i.first]);
            }
            helper(i+1,words,sum);
            for(auto i:m1)
            {
                sum-=(i.second*sc[i.first]);
            }
        }
        for(auto& p:m1) m[p.first]+=p.second; 
        helper(i+1,words,sum);

    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        

        for(auto i:letters)
        m[i]++;

        for(int i=0;i<score.size();i++)
        {
            sc['a'+i]=score[i];
        }

        helper(0,words,0);

        return ans;

    }
};