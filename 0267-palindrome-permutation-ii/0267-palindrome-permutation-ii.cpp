class Solution {
public:
    set<string> st;
    void helper(int i,int n,string str,map<char,int> &m)
    {
         if(i==n)
         {
            st.insert(str);
            return;
         }

        for(auto &j:m)
        {
            if(j.second>0){
            str+=j.first;
            j.second--;
            helper(i+1,n,str,m);
            str.pop_back();
            j.second++;

            }
            
        }
        
    }
    vector<string> generatePalindromes(string s) {

        map<char,int> m;
        set<string> st1;
        int n=s.length()/2;

        for(auto i:s)
        {
            m[i]++;
        }

        int cnt=0;
        char c;
        for(auto i:m)
        {
            if(i.second%2==1){
                c=i.first;
                cnt++;
                }
        }

        if(cnt>1)return {};

        string str;
        if(cnt==1 && m.count(c))
        {
            m[c]--;
        }
        for(auto &i:m)
        {
            if(i.second%2==0)
            {
                i.second/=2;
            }
        }

        helper(0,n,str,m);


        for(auto i:st)
        {
            
            string abc=i;
            string xyz=i;
            reverse(xyz.begin(),xyz.end());

                if(cnt==1)
                {
                    abc+=c;
                }
                abc+=xyz;

            st1.insert(abc);
        }

        vector<string> ans(st1.begin(),st1.end());


        return ans;
        
    }
};