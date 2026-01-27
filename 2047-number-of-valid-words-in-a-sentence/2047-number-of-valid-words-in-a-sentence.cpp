class Solution {
public:
    int countValidWords(string sentence) {
        
        int ans=0;

        int i=0;

        while(i<sentence.length())
        {
            if(sentence[i]==' ')i++;
            else 
            {
                string str;
                while(i<sentence.length() && sentence[i]!=' ')
                {
                    str+=sentence[i];
                    i++;
                }

                bool flag1=false;
                bool flag2=false;
                int cnt2=0,cnt3=0;
                bool flag3=false;
                cout<<str<<"  ";
                for(int j=0;j<str.length();j++)
                {
                    if(isdigit(str[j]))
                    {
                        flag1=true;
                        break;
                    }
                    else if(str[j]=='-')
                    {
                        cnt2++;
                    if(j==0 || j==str.length()-1 ||!isalpha(str[j-1]) ||!isalpha(str[j+1]))
                        {
                            flag2=true;
                            break;
                        }
                    }
                    else if(str[j]=='!' || str[j]=='.' || str[j]==',')
                    {
                        cnt3++;
                        if(j>=0 && j<str.length()-1)
                        {
                            flag3=true;
                            break;
                        }
                    }               
                }

                if(!flag1 && !flag2 && !flag3 && cnt2<=1 && cnt3<=1)
                ans++;
                cout<<ans<<endl;
            }
        }

        return ans;
    }
};