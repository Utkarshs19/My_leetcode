class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        
        set<int> st;

        for(auto i:arr1)st.insert(i);

        set<int> st1;

        vector<int> ans;

        for(auto i:arr2)
        {
            if(st.count(i))st1.insert(i);
        }

        for(auto i:arr3)
        {
            if(st1.count(i))ans.push_back(i);
        }

        return ans;
    }
};