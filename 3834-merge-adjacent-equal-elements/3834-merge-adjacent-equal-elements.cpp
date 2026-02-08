class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        stack<long long> st;

        for(int i=0;i<nums.size();i++)
        {
            if(st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                long long k=nums[i];
               
                while(!st.empty() && st.top()==k)
                {
                    st.pop();
                    k=2*k;
                }
                
                st.push(k);
            }
        }

        vector<long long> ans;

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};