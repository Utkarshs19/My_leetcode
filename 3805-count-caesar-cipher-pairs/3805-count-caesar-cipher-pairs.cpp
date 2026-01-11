class Solution {
public:
    long long countPairs(vector<string>& words) {

        int n=words.size();
        vector<long long> suf(n);

        long long ans=0;

        map<string,int> m1;
        suf[n-1]=0;
        m1[words[n-1]]=n-1;

        for(int i=n-2;i>=0;i--)
            {
                map<string,int> m;
                string str=words[i];
                for(int j=0;j<26;j++)
                    {
                        string s=str;
                        for(int k=0;k<str.length();k++)
                            {
                                if(str[k]=='z')
                                {
                                    str[k]='a';
                                }
                                else
                                {
                                    str[k]=str[k]+1;
                                }
                            }
                        m[str]++;

                        if(m1.count(str))
                        {
                            ans+=suf[m1[str]]+1;
                            suf[i]=suf[m1[str]]+1;
                            m1.erase(str);
                        }

                    }   
                
                    m1[words[i]]=i;
            }                

        return ans;
        
    }
};