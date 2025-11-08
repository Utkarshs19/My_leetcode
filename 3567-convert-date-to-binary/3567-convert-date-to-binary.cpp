class Solution {
public:
    string convertDateToBinary(string date) {

        string ans="";

        int i=0,j=0;

        while(j<date.length() )
        {
            i=j;
            int x=0;
            while(date[i]!='-' && i!=date.length())
            {
                x=x*10+(date[i]-'0');
                i++;
            }
            string str="";
            while(x>0)
            {
                str+=to_string(x%2);
                x=x/2;
            }
            reverse(str.begin(),str.end());
            ans+=str;
            ans+='-';

            i++;
            j=i;
        }
        ans.pop_back();

        return ans;
        
    }
};