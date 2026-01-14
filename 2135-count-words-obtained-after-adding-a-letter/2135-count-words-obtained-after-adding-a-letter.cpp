class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    
        set<string> st;

        for(int i=0;i<startWords.size();i++)
        {
            string base = startWords[i];
            sort(base.begin(), base.end());

            for (int j = 0; j < 26; j++) {
                char c = 'a' + j;
                if (base.find(c) != string::npos) continue; 

                string str = base;
                str.push_back(c);
                sort(str.begin(), str.end());
                st.insert(str);
            }
        }
        
        int ans=0;

        for(int i=0;i<targetWords.size();i++)
        {
            sort(targetWords[i].begin(),targetWords[i].end());
            if(st.count(targetWords[i]))ans++;
        }

        return ans;

        
    }
};