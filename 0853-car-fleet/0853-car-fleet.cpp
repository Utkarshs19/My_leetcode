class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++)
        {
            v.push_back({position[i],speed[i]});
        }

        sort(v.rbegin(),v.rend());

        stack<double> st;

        for(int i=0;i<v.size();i++)
        {
            double x=(double)(target-v[i].first)/v[i].second;

            if(st.empty())
            {
                st.push(x);
            }
            else
            {
                if(x>st.top())
                {
                    st.push(x);
                }
            }
        }

        return st.size();
        
    }
};