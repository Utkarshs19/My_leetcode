class Solution {
public:

    bool helper(int k,string &s,string &p,vector<int>& removable)
    {
        string str;
        int i=0,j=0;
        set<int> st;
        for(j=0;j<k;j++)
        st.insert(removable[j]);

        for(i=0;i<s.length();i++)
        {
            if(st.count(i))continue;
            str+=s[i];
        }

        i=0;
        j=0;

        while(i<str.length() && j<p.length())
        {
            if(str[i]==p[j])
            {
                i++;
                j++;
            }
            else i++;
        }

        if(j==p.length())return true;
        return false;
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {

        int low=0;
        int high=removable.size();

        int ans=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(helper(mid,s,p,removable))
            {
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }

        return ans;
        
    }
};