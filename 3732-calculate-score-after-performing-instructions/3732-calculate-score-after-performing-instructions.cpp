class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {

        set<int> st;

        long long sum=0;

        int i=0,n=values.size();

        while(i<n && i>=0)   
        {
            if(st.find(i)!=st.end())
            return sum;

            if(instructions[i]=="add")
            {
                sum+=values[i];
                st.insert(i);

                i+=1;
            }
            else
            {
                st.insert(i);
                i+=values[i];

            }
        }


        return sum;
        
    }
};