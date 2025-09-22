class Solution {
public:
    int maxScore(string s) {

        int zero=0;
        int one=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')one++;
        }

        int maxi=0;

        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0')zero++;
            else
            one--;

            cout<<zero<<"  "<<one<<endl;
            maxi=max(maxi,zero+one);
        }


        return maxi;
        
    }
};