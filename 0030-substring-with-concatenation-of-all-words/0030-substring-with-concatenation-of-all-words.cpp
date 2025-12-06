class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;
        if(words.empty()) return ans;

        int n = s.length();
        int w = words[0].size();
        int total = words.size() * w;

        map<string,int> m;
        for(auto &word : words) m[word]++;

        
        for(int k = 0; k < w; k++)
        {
            int i = k, j = k;
            map<string,int> m1;

            while(j + w <= n)
            {
                string word = s.substr(j, w);

                if(m.find(word) == m.end())
                {
                    m1.clear();
                    i = j + w;
                }
                else
                {
                    m1[word]++;

                    
                    while(m1[word] > m[word])
                    {
                        string left = s.substr(i, w);
                        m1[left]--;
                        if(m1[left] == 0) m1.erase(left);
                        i += w;
                    }

                    if(j - i + w == total)
                        ans.push_back(i);
                }

                j += w;
            }
        }

        return ans;
    }
};
