class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {

        vector<string> ans;
        map<string,int> m;

        for(int i=0;i<arr.size();i++)
        {
            string s=arr[i];

            for(int j=0;j<s.length();j++)
            {
                string str="";
                for(int k=j;k<s.length();k++)
                {
                    str+=s[k];
                    m[str]++;
                }
            }
        }

        for(auto i:m)
        cout<<i.first<<" "<<i.second<<endl;

        for(int i=0;i<arr.size();i++)
        {
            string s=arr[i];

            vector<string> v;

            for(int j=0;j<s.length();j++)
            {
                string str="";
                for(int k=j;k<s.length();k++)
                {
                    str+=s[k];
                    v.push_back(str);
                    m[str]--;
                    if(m[str]==0)m.erase(str);
                }
            }

            sort(v.begin(), v.end(), [](const string &a, const string &b) {
    if (a.size() == b.size()) return a < b; // lexicographic
    return a.size() < b.size();             // shorter first
});

            

            bool flag=true;
             for(int j=0;j<v.size();j++)
            {
                if(m.find(v[j])==m.end()){
                ans.push_back(v[j]);
                flag=false;
                break;
                }
            }
                if(flag==true)
                ans.push_back("");

                for(int k=0;k<v.size();k++)
                {
                    m[v[k]]++;
                }
            
        }

        return ans;

        
    }
};