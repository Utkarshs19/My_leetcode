class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {

        map<string,int> m;
        int x=0;
        for(int i=0;i<word.length();i+=k)
        {
            string str;
            for(int j=i;j<i+k;j++)
            {
                str+=word[j];
            }
            m[str]++;
            x=max(x,m[str]);
        }

        return word.length()/k-x;
        
    }
};