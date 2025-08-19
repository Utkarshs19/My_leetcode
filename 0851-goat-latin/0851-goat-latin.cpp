class Solution {
public:
    string toGoatLatin(string sentence) {

        sentence+=" ";
        string ans="";
        string a="a";
        string x="";

        for(int i=0;i<sentence.size();i++)
        {
            
            if(sentence[i]==' ')
            {
                if(x[0]=='a'||x[0]=='e'||x[0]=='i'||x[0]=='o'||x[0]=='u'||x[0]=='A'||x[0]=='E'||x[0]=='I'||x[0]=='O'||x[0]=='U')
                {
                    x+="ma";
                    x+=a;
                    x+=" ";
                    a+="a";
                    ans+=x;
                    x="";
                }
                else
                {
                    char c=x[0];
                    x=x.substr(1,x.length()-1);
                    x+=c;
                    x+="ma";
                    x+=a;
                    x+=" ";
                    a+="a";
                    ans+=x;
                    x="";
                }
            }   
            else
            x+=sentence[i]; 
        }        

        return ans.substr(0,ans.length()-1);
    }
};