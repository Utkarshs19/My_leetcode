class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {

        set<string> st;
        for(int i=0;i<bannedWords.size();i++)
        {
            st.insert(bannedWords[i]);
        }

        int cnt=0;

        for(int i=0;i<message.size();i++)
        {
            if(st.find(message[i])!=st.end())
            {
                cnt++;
            }
        }

        return cnt>=2;
        
    }
};