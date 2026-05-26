class Solution {
public:
    void reverseWords(vector<char>& s) {

        int i=0,j=s.size()-1;

        while(i<=j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }

         i=0;
        string str;
     j=0;

        while(i<s.size())
        {
            str="";
            while(i<s.size() && s[i]!=' '){
                str+=s[i];
                i++;
            }
            cout<<str<<endl;
            int k=str.length()-1;
        

            while(j<i)
            {
                s[j]=str[k];
                j++;
                k--;
            }

            i++;
            j++;
            
        }
        
    }
};