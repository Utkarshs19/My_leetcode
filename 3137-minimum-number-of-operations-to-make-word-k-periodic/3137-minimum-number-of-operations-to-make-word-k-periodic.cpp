class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {

        map<string,int> m;
        int x=0;
        for(int i=0;i<word.length();i+=k)
        {
            m[word.substr(i,k)]++;
            x=max(x,m[word.substr(i,k)]);
        }

        return word.length()/k-x;
        
    }
};