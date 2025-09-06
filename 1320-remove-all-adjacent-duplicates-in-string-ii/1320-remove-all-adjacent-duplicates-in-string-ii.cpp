class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char,int>> st;

        st.push({s[0],1});

        for(int i=1;i<s.length();i++)
        {
            if(!st.empty()){
            char x=st.top().first;
            int y=st.top().second;

            if(s[i]==x)
            {
                if((1+y)==k)
                st.pop();
                else{
                    st.pop();
                st.push({x,y+1});}
            }
            else
            st.push({s[i],1});
            }
            else
            st.push({s[i],1});
        }

        string ans="";
        while(!st.empty())
        {
            int y=st.top().second;
            while(y>0){
            ans+=st.top().first;
            y--;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};