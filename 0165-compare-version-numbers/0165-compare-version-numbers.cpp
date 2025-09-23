class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<string> v1,v2;

        int i=0,j=0;

        string s="";
        version1+='.';
        version2+='.';

        while(j<version1.length())
        {
            if(version1[j]=='.')
            {
                v1.push_back(s);
                i=j;
                j++;
                i++;
                s="";
            }
            else
            {
                s+=version1[j];
                j++;
            }
        }
        i=0;
        j=0;
         while(j<version2.length())
        {
            if(version2[j]=='.')
            {
                v2.push_back(s);
                i=j;
                j++;
                i++;
                s="";
            }
            else
            {
                s+=version2[j];
                j++;
            }
        }

        if(v1.size()<v2.size())
        {
            int j=v1.size();
            while(j<v2.size())
            {
                v1.push_back("0");
                j++;
            }
        }
        else
        {
            int j=v2.size();
            while(j<v1.size())
            {
                v2.push_back("0");
                j++;
            }
        }


        for(int i=0;i<v1.size();i++)
        {
            if(stoi(v1[i])<stoi(v2[i]))return -1;
            if(stoi(v1[i])>stoi(v2[i]))return 1;
        }

        return 0;

        

    }
};