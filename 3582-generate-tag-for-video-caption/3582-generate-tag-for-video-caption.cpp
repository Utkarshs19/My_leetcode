class Solution {
public:
    string generateTag(string caption) {

        string ans="#";

        int i=0,j=0;
        bool flag=false;
        while(i<caption.length())
        {
            if(isalpha(caption[i]))
            {
                if(flag==true && ans.back()!='#'){
                ans+=(toupper(caption[i]));
                }
                else
                ans+=tolower(caption[i]);

                flag=false;
            }
            if(caption[i]==' ')flag=true;
            i++;
        }

        return ans.substr(0,min((int)(ans.length()),100));
        
    }
};