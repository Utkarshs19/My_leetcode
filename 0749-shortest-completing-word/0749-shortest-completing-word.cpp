class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {

        map<char,int> m;

        string ans="";

        for(int i=0;i<licensePlate.length();i++)
        {
            if(isalpha(licensePlate[i]))
            m[tolower(licensePlate[i])]++;
        }

        sort(words.begin(),words.end());

        for(int i=0;i<words.size();i++)
        {
            map<char,int> m1;

            for(int j=0;j<words[i].length();j++)
            {
                m1[words[i][j]]++;
            }

            bool flag=true;

            for(auto k:m)
            {
                if(m1.find(k.first)!=m1.end())
                {
                    if(m[k.first]>m1[k.first])
                    {
                        flag=false;
                        break;
                    }

                }
                else
                flag=false;

                if(flag==false)
                break;

            }

            if(flag==true){
            if(ans=="")
            ans=words[i];
            else
            {
                if(ans.length()>words[i].length())
                ans=words[i];
            }
            }
        }

        return ans;
        
    }
};