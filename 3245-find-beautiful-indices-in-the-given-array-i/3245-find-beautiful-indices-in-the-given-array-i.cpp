class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        vector<int> v1,v2;

        if(s.length()<a.length())return {};
        if(s.length()<b.length())return {};

        for(int i=0;i<=(s.length()-a.length());i++)
        {
            if(s.substr(i,a.length())==a)
            v1.push_back(i);
        }

        for(int i=0;i<=(s.length()-b.length());i++)
        {
            if(s.substr(i,b.length())==b)
            v2.push_back(i);
        }

        for(int i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<v2.size();i++)
        {
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        
        vector<int> ans;

        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                if(abs(v2[j]-v1[i])<=k){ans.push_back(v1[i]);break;}
            }
        }

        return ans;


    }
};