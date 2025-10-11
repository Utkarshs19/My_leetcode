class Solution {
public:
    unordered_set<string> st;

    int helper(int i,string &s)
    {
        if(i==s.size())return 0;

        int maxi=0;

        for(int j=i+1;j<=s.size();j++)
        {
            string str=s.substr(i,j-i);
            if(st.find(str)==st.end())
            {
                st.insert(str);

                maxi=max(maxi,1+helper(j,s));

                st.erase(str);
            }
        }

        return maxi;
    }

    int maxUniqueSplit(string s) {

        return helper(0,s);
        
    }
};