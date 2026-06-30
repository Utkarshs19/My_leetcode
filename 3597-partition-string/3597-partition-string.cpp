class Solution {
public:
    vector<string> partitionString(string s) {
        
        set<string> st;
        vector<string> ans;
     
        string str;
        for(int i=0;i<s.length();i++)
        {
            str+=s[i];
            if(!st.count(str))
            {
                ans.push_back(str);
                
                st.insert(str);
                str="";
            }
        }
        if(str.length()>0 && !st.count(str))
        ans.push_back(str);

        
        return ans;


    }
};