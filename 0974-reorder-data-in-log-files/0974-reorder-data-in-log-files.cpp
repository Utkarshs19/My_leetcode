class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<string> dig;
        vector<string> alpha;

        for(int i=0;i<logs.size();i++)
        {
            if(isdigit(logs[i].back()))
            dig.push_back(logs[i]);
            else
            alpha.push_back(logs[i]);
        }


        map<string,vector<string>> m;

        for(int i=0;i<alpha.size();i++)
        {
            int j=0;
            while(j<alpha[i].length())
            {
                if(alpha[i][j]==' ')
                {
                    m[alpha[i].substr(j+1)].push_back(alpha[i].substr(0,j));
                    break;
                }
                j++;
            }
        }

        vector<string> ans;

        for(auto i:m)
        {
            vector<string> v=i.second;
            sort(v.begin(),v.end());
            for(int j=0;j<v.size();j++){
            string s=v[j];
            s+=" ";
            s+=i.first;


            ans.push_back(s);
            }
        }

        for(auto i:dig)
        ans.push_back(i);

        return ans;
        
    }
};