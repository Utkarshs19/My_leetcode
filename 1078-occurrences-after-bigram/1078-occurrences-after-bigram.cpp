class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {

        vector<string> ans;

        string f="",s="",str="";

        int i=0,j=0;

        while(j<text.length())
        {
            while(j<text.length() && text[j]!=' ')
            {
                str+=text[j];
                j++;
            }
            if(f=="")
            {
                f=str;
                str="";
                j++;
            }
            else if(f!="" && s=="")
            {
                s=str;
                str="";
                j++;
            }
            else
            {
                if(f==first && s==second)
                    ans.push_back(str);

                    f=s;
                    s=str;
                    str="";
                    j++;
                
            }
        }
        
        return ans;
    }
};