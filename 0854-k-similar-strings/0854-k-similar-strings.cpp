class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int ans=0;
        queue<string> q;
        q.push(s1);

        unordered_set<string> st;
        st.insert(s1);

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string str=q.front();
                q.pop();

                if(str==s2)return ans;
                
               int j=0;
               while(str[j]==s2[j])j++;

               for(int k=j+1;k<str.length();k++)
               {
                    if (str[k] == s2[j] && str[k] != s2[k]) {
                        swap(str[j], str[k]);
                        if (!st.count(str)) {
                            st.insert(str);
                            q.push(str);
                        }
                        swap(str[j], str[k]);
                    }
               }
                
            }
            ans++;
        }

        return -1;
        
    }
};