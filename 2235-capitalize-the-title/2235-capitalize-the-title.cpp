class Solution {
public:
    string capitalizeTitle(string title) {

        int i=0,j=0;
        title+=" ";

        string ans="";

        while(j<title.length())
        {
            if(title[j]==' ')
            {
                if(j-i<=2)
                {
                    while(i<j)
                    {
                        ans+=tolower(title[i]);
                        i++;
                    }
                }
                else
                {
                    ans+=toupper(title[i]);
                    i++;
                    while(i<j)
                    {
                        ans+=tolower(title[i]);
                        i++;
                    }
                }
                ans+=" ";
                i++;
                j++;
            }
            else
            j++;
        }

        return ans.substr(0,ans.length()-1);
    }
};