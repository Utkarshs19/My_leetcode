class Solution {
public:
    int compareVersion(string version1, string version2) {

        int i=0,j=0;

        version1+='.';
        version2+='.';

        int n1=version1.length();
        int n2=version2.length();

        string str1="";
        string str2="";

        int x=0,y=0;



        if(n1>n2){
        while(i<n1)
        {
            if(version1[i]=='.')
            {
                while(j<n2&&version2[j]!='.')
                {
                    str2+=version2[j];
                    j++;
                }

                if(str2=="")str2="0";

                cout<<"1  ->"<<str1<<"  "<<"2 -->"<<str2<<endl;

                x=0;
                x=stoi(str1);
                str1="";
                i++;

                y=0;
                y=stoi(str2);
                str2="";
                j++;

                if(x!=y)
                {
                    return x<y?-1:1;
                }

            }
            else
            {
                str1+=version1[i];
                i++;
            }
        }
        }
        else
        {

            while(j<n2)
            {   
            if(version2[j]=='.')
            {
                while(i<n1&&version1[i]!='.')
                {
                    str1+=version1[i];
                    i++;
                }

                if(str1=="")str1="0";

                cout<<"1  ->"<<str1<<"  "<<"2 -->"<<str2<<endl;

                x=0;
                x=stoi(str1);
                str1="";
                i++;

                y=0;
                y=stoi(str2);
                str2="";
                j++;

                if(x!=y)
                {
                    return x<y?-1:1;
                }

            }
            else
            {
                str2+=version2[j];
                j++;
            }
        }

        }
        

        return 0;
    }
};