class Solution {
public:
    bool valid(string str)
    {
        stack<char> st;
        int j=0;
        while(j<str.length())
        {
            if(str[j]=='(')st.push('(');
            else if(str[j]==')')
            {
                if(!st.empty() && st.top()=='(')st.pop();
                else return false;
            }
            j++;
        }
        return st.size()==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        
        queue<string> q;
        set<string> vis;
        q.push(s);
        vis.insert(s);

        bool flag=false;
        set<string> st;

        while(!q.empty())
        {
            int size=q.size();
            if(flag)break;
            for(int i=0;i<size;i++)
            {
                string str=q.front();
                q.pop();
            
                if(valid(str))
                {
                    flag=true;
                    st.insert(str);
                }

                for(int j=0;j<str.length();j++)
                {
                    if(isalpha(str[j]))continue;
                    else
                    {
                        string p=str.substr(0,j);
                        p+=str.substr(j+1);

                        if(!vis.count(p))
                        {
                            vis.insert(p);
                            q.push(p);
                        }
                    }
                }
            }
        }

        return vector<string>(st.begin(),st.end());
    }
};