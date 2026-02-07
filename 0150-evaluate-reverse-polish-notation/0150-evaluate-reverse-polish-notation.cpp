class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();

                if(tokens[i]=="+")
                st.push(x+y);
                if(tokens[i]=="-")
                st.push(y-x);
                if(tokens[i]=="*")
                st.push(x*y);
                if(tokens[i]=="/")
                st.push(y/x);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }

        }

        return st.top();
        
    }
};
