class Solution {
public:
    int minMaxDifference(int num) {

        string str=to_string(num);

        string maxi=str;
        string mini=str;

        int i=0;
        char x,y;
        while(i<str.length())
        {
            if(str[i]=='9')
            {
                i++;
            }
            else
            {
                x=str[i];
                break;
            }
        }

        i=0;
        while(i<str.length())
        {
            if(str[i]=='0')
            {
                i++;
            }
            else
            {
                y=str[i];
                break;
            }
        }

        for(int i=0;i<str.length();i++)
        {
            if(str[i]==x)
            {
                maxi[i]='9';
            }
            if(str[i]==y)
            {
                mini[i]='0';
            }
        }

        return stoi(maxi)-stoi(mini);
        
    }
};