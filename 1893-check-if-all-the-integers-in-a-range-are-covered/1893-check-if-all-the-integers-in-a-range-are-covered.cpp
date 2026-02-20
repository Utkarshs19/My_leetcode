class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        set<int> st;
        for(int i=left;i<=right;i++)
        {
            st.insert(i);
        }

        for(int i=0;i<ranges.size();i++)
        {
            for(int j=ranges[i][0];j<=ranges[i][1];j++)
            {
                if(st.count(j))
                st.erase(j);
            }
        }
        
        return st.size()==0;
    }
};