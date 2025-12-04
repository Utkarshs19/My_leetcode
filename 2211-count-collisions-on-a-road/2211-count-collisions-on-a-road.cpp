class Solution {
public:
    int countCollisions(string directions) {

        stack<char> st;
        int sum = 0;

        for (char c : directions) {

            if (c == 'L') {
                if (!st.empty() && st.top() == 'R') {
               
                    sum += 2;
                    st.pop();

                    while (!st.empty() && st.top() == 'R') {
                        sum += 1;
                        st.pop();
                    }

                    st.push('S'); 
                }
                else if (!st.empty() && st.top() == 'S') {
                   
                    sum += 1;
                    st.push('S');
                }
                else {
                    st.push('L');
                }
            }

            else if (c == 'S') {

                
                while (!st.empty() && st.top() == 'R') {
                    sum += 1;
                    st.pop();
                }
                st.push('S');
            }

            else { 
                st.push('R');
            }
        }

        return sum;
    }
};
