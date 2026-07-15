class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        set<int> st;
        for(int i=0;i<n;i++)st.insert(i);

        vector<int> ans;

        for(int i=0;i<queries.size();i++)
        {
            auto start=st.lower_bound(queries[i][0]+1);
            auto end=st.upper_bound(queries[i][1]-1);

            st.erase(start,end);

            ans.push_back(st.size()-1);
        }
        return ans;
        
    }
};