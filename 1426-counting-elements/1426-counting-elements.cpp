class Solution {
public:
    int countElements(vector<int>& arr) {

        multiset<int> st;

        for(auto i:arr)st.insert(i);

        int ans=0;

        for(auto i:st)
        {
            if(st.count(i+1))ans++;
        }
        return ans;
        
    }
};