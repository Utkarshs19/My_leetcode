class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        map<string,vector<string>> m;

        for(int i=0;i<code.size();i++)
        {
            if(isActive[i]==true && code[i].length()>0)
            {
                bool flag=true;
                for(int j=0;j<code[i].length();j++)
                {
                    if(!(isalnum(code[i][j])) && code[i][j]!='_')
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                m[businessLine[i]].push_back(code[i]);
                }
            }
        }

            vector<string> ans;

            
            vector<string> v=m["electronics"];
            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++)
            {
                ans.push_back(v[i]);
            }
            v.clear();

            v=m["grocery"];
            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++)
            {
                ans.push_back(v[i]);
            }
            v.clear();

            v=m["pharmacy"];
            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++)
            {
                ans.push_back(v[i]);
            }

            v.clear();
            v=m["restaurant"];
            sort(v.begin(),v.end());

            for(int i=0;i<v.size();i++)
            {
                ans.push_back(v[i]);
            }



            return ans;
        
    }
};