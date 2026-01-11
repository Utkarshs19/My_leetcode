class Solution {
public:
    long long countPairs(vector<string>& words) {

        long long ans=0;

        unordered_map<string,long long> m;

        int n=words.size();

        for(int i=n-1;i>=0;i--)
        {
            string str=words[i];
            for(int j=0;j<26;j++)
            {
                if(m.count(str))
                {
                    ans+=m[str];
                }
                for (char &c : str) {
                    c = (c == 'z') ? 'a' : c + 1;
                }
            }
            m[words[i]]++;
        }

        return ans;
        
    }
};