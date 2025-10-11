class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        set<string> st;

        for(int i=0;i<word.length();i++)
        {
            string str="";
            for(int j=i;j<word.length();j++)
            {
                str+=word[j];

                st.insert(str);
            }
        }

        int cnt=0;

        for(int i=0;i<patterns.size();i++)
        {
            if(st.find(patterns[i])!=st.end())cnt++;
        }

        return cnt;
        
    }
};