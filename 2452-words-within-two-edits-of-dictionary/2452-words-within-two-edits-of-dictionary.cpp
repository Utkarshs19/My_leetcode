class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> ans;

        for(int i=0;i<queries.size();i++)
        {
            for(int j=0;j<dictionary.size();j++)
            {
                if(queries[i].length()==dictionary[j].length()){
                if(queries[i]==dictionary[j])
                {
                    ans.push_back(queries[i]);
                    break;
                }
                else
                {
                    string x=queries[i];
                    string y=dictionary[j];
                    int cnt=0;
                    for(int i=0;i<x.length();i++)
                    {
                        if(x[i]!=y[i])cnt++;
                    }
                    if(cnt<=2){
                        ans.push_back(queries[i]);
                        break;
                        }
                
                }
                }
            }
        }
        return ans;        
    }
};