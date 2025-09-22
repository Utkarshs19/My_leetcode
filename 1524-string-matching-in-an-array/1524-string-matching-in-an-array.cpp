class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string> ans;
        set<string> st;

        for(int i=0;i<words.size();i++)
        {
            string s=words[i];

            for(int j=0;j<words.size();j++)
            {
                if(j==i)continue;
                string str=words[j];

                if(s.length()<=str.length())
                {
                    for(int k=0;k<(str.length());k++)
                    {
                        if(str.substr(k,s.length())==s){
                            st.insert(s);
                            break;
                        }
                    }
                }
            }
        }

        for(auto it=st.begin();it!=st.end();++it)
        ans.push_back(*it);

        return ans;
    }
};