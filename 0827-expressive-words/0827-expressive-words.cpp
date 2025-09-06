class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {

        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            
            int cnt1=0;
            int cnt2=0;

            int j=0,k=0;

            while(j<s.length()&&k<str.length())
            {
                if(s[j]!=str[k])break;
                    int a=j;
                    int b=k;
                if(s[j]==str[k])
                {
                    while(a<s.length())
                    {
                        if(s[a]==s[j])a++;
                        else break;
                    }
                    while(b<str.length())
                    {
                        if(str[b]==str[k])b++;
                        else break;
                    }
                }
                    if((a-j)<(b-k))break;
                    if((a-j)!=(b-k)&&(a-j)<3)break;

                    j=a;
                    k=b;
            }
            cout<<j<<"  "<<k<<endl;
            if(j==s.length()&&k==str.length())ans++;

        }

        return ans;
        
    }
};