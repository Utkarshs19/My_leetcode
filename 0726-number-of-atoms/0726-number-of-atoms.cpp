class Solution {
public:
    string countOfAtoms(string formula) {

        stack<pair<string,int>> st;

        map<string,int> m;

        for(int i=0;i<formula.length();)
        {
            if(isalpha(formula[i]) && isupper(formula[i]))
            {
                string str;
                str+=formula[i];
                i+=1;
                while(i<formula.length() && islower(formula[i]))
                {
                    str+=formula[i];
                    i++;
                }
                int x=0;
                if(i<formula.length() && isdigit(formula[i]))
                {
                    while(i<formula.length() && isdigit(formula[i]))
                    {
                        x=x*10+(formula[i]-'0');
                        i++;
                    }
                }
                if(x==0)x=1;

                st.push({str,x});
            }
            else if(formula[i]=='(')
            {
                st.push({"(",-1});
                i++;
            }
            else if(formula[i]==')')
            {
                i++;
                int x=0;
                while(i<formula.length() && isdigit(formula[i]))
                {
                    x=x*10+(formula[i]-'0');
                    i++;
                }
                if(x==0)x=1;

                stack<pair<string,int>> s;

                while(!st.empty() && st.top().first!="(")
                {
                    string str=st.top().first;
                    int y=st.top().second;
                    st.pop();
                    s.push({str,x*y});

                }
                if(st.top().first=="(")st.pop();
                while(!s.empty())
                {
                    st.push({s.top().first,s.top().second});
                    s.pop();
                }
            }
           
        }

        while(!st.empty())
        {
            m[st.top().first]+=st.top().second;
            st.pop();
        }

        string ans;

        for(auto i:m)
        {
            ans+=i.first;
            if(i.second==1)continue;
            ans+=to_string(i.second);
        }

        return ans;
        
         
        
    }
};