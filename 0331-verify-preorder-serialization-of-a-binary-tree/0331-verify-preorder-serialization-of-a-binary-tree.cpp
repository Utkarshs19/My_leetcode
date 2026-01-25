class Solution {
public:
    bool isValidSerialization(string preorder) {

        stack<int> st;
        int n=preorder.length();
        int j=0;

        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == ',') continue;

            if (preorder[i] == '#') {
                st.push(-1);
                i++;
            } else {
                while (i < n && preorder[i] != ',') i++;
                st.push(1);   
            }

            while(st.size()>=3)
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int c = st.top();

                if (a == -1 && b == -1 && c != -1) {
                    st.pop();
                    st.push(-1);
                } else {
                    st.push(b);
                    st.push(a);
                    break;
                }
            }

            
        }

        
        return st.size()==1 && st.top()==-1;
        
    }
};