class Solution {
public:

    bool palindrome(string str,int i,int j)
    {

        while(i<j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else
            return false;
        }

        return true;
    }

    bool check(const string &str1, const string &str2 )
    {
        int i=0,j=str1.length()-1;

        while(i<j&&str1[i]==str2[j])
        {
            i++;
            j--;
        }

        return palindrome(str1,i,j)||palindrome(str2,i,j);
    }


    bool checkPalindromeFormation(string a, string b) {

        return check(a,b)||check(b,a);

    }
};