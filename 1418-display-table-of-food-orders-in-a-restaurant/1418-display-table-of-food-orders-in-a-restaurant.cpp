class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {

        vector<vector<string>> ans;
        map<int,map<string,int>> m;

        set<string> st;

        for(int i=0;i<orders.size();i++)
        {
            m[stoi(orders[i][1])][orders[i][2]]++;
            st.insert(orders[i][2]);
        }

        vector<string> v;
        v.push_back("Table");
        for(auto i:st)
        v.push_back(i);

        ans.push_back(v);

        v.clear();
        for(auto i:m)
        {
            v.push_back(to_string(i.first));
            for(auto k:st)
            {
                if(m[i.first].count(k))
                {
                    v.push_back(to_string(m[i.first][k]));
                }
                else
                v.push_back("0");
            }
            ans.push_back(v);
            v.clear();
        }

        return ans;
        
    }
};