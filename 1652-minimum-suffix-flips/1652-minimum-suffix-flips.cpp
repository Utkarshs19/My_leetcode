class Solution {
public:
    int minFlips(string target) {

        char c='0';

        int cnt=0;

        for(int i=0;i<target.length();i++)
        {
           if(target[i]!=c)
           {
                cnt++;

                c=target[i];
           }
        }
        return cnt;        
    }
};