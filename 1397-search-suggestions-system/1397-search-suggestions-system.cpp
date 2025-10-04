class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {

        vector<vector<string>> ans;

        map<string,vector<string>> m;

        for(int i=0;i<products.size();i++)
        {
            string str=products[i];

            for(int j=0;j<str.length();j++)
            {
                m[str.substr(0,j+1)].push_back(str);
            }
        }

        for(int i=0;i<searchWord.length();i++)
        {
            vector<string> abc;
            if(m.find(searchWord.substr(0,i+1))!=m.end())
            {   
                vector<string> v=m[searchWord.substr(0,i+1)];
                sort(v.begin(),v.end());
             
                for(int i=0;i<v.size();i++)
                {
                    if(abc.size()==3)
                    break;
                    
                    abc.push_back(v[i]);
                }

            }

            ans.push_back(abc);
        }

        return ans;
        
    }
};