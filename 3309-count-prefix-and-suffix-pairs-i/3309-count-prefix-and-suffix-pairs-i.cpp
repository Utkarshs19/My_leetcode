class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int cnt=0;

        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            int n1=s.length();
            for(int j=i+1;j<words.size();j++)
            {
                string str=words[j];

                int n2=str.length();

                if(n1<=n2)
                {
                    if(str.substr(0,n1)==s && str.substr(n2-n1)==s)cnt++;
                }

            }
        }
        return cnt;
    }
};