class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {

        int i=0,j=0,k=0;

        int cnt=0;

        while(i<s1.length() && j<s2.length() && k<s3.length())
        {
            if(s1[i]==s2[j] && s2[j]==s3[k])
            {
                i++;
                j++;
                k++;
            }
            else if(i==0 || j==0 ||k==0)
            return -1;
            else
            {
                cnt+=s1.length()-i;
                i=s1.length();
                cnt+=s2.length()-j;
                j=s2.length();
                cnt+=s3.length()-k;
                k=s3.length();

                break;
            }
        }

        if(i<s1.length())
        cnt+=s1.length()-i;

        if(j<s2.length())
        cnt+=s2.length()-j;

        if(i<s3.length())
        cnt+=s3.length()-k;



        return cnt;
        
    }
};