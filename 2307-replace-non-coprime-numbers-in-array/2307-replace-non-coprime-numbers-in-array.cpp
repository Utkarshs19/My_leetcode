class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        stack<long long int> st;

        for(int i=0;i<nums.size();i++)
        {
            long long x=nums[i];
            while(!st.empty()&&(gcd(st.top(),x))>1)
            {
                long long top=st.top();
                st.pop();
                
               x=(top/gcd(top,x))*x;
            }
            st.push(x);
        }

        
        
        vector<int> ans;

    while(!st.empty()){
    ans.push_back(st.top());
    st.pop();}

    reverse(ans.begin(),ans.end());

    return ans;

         
    }
};