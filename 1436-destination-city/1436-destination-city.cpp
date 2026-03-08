class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        set<string> st;
        for(int i=0;i<paths.size();i++)
        {
            st.insert(paths[i][0]);
        }

        for(int i=0;i<paths.size();i++)
        {
            if(!st.count(paths[i][1]))return paths[i][1];
        }

        return "";
        
    }
};