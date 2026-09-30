class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        
        vector<int> ans;
        stack<char> st;

        for(int i=0;i<seq.length();i++)
        {
            if(seq[i]==')')st.pop();
            ans.push_back(st.size()%2);
            if(seq[i]=='(')st.push(seq[i]);
        }

        return ans;

    }
};