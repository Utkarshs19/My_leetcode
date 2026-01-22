class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {

        int ans=INT_MAX;
        set<int> st;
        vector<int> v;
        for(int i=0;i<fronts.size();i++)
        {
            if(fronts[i]==backs[i]){
            st.insert(fronts[i]);
            continue;
            }
            else
            {   
                v.push_back(fronts[i]);
                v.push_back(backs[i]);
            }
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            if(!st.count(v[i]))
            ans=min(ans,v[i]);
        }
        
        return ans==INT_MAX?0:ans;
    }
};