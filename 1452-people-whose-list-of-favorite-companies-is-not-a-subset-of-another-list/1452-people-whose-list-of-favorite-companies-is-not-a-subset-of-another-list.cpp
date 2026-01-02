class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {

        vector<int> ans;

        vector<set<string>> v;

        for(int i=0;i<favoriteCompanies.size();i++)
        {
            set<string> s;
            for(int j=0;j<favoriteCompanies[i].size();j++)
            {
                s.insert(favoriteCompanies[i][j]);
            }
            v.push_back(s);
        }

        for(int i=0;i<v.size();i++)
        {
            auto &a=v[i];
            bool flag=false;
            for(int j=0;j<v.size();j++)
            {
                if(i==j)continue;

                auto &b=v[j];
                if(b.size()<a.size())continue;
                bool isSubset = true;
                for (auto &k : a) {
                    if (b.find(k) == b.end()) {
                        isSubset = false;
                        break;
                    }
                }

                if (isSubset) {
                    flag = true;
                    break;
                }

            }

            if(!flag)
            ans.push_back(i);
        }
        return ans;
    }
};