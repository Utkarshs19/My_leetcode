class Solution {
public:
    string largestMerge(string word1, string word2) {

        string ans="";

        int i=0;
        int j=0;

        int n1=word1.length();
        int n2=word2.length();

        while(i<n1 && j<n2)
        {
            if(word1.substr(i)>word2.substr(j))
            {
                ans+=word1[i];
                i++;
            }
            else
            {
                ans+=word2[j];
                j++;
            }
        }    

        ans+=word1.substr(i);
        ans+=word2.substr(j);



        return ans;
        
    }
};