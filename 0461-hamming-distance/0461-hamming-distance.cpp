class Solution {
public:
    int hammingDistance(int x, int y) {

        int ans=0;

        set<int> st;
        int k=0;
        while(x>0)
        {
            if(x%2==1)st.insert(k);
            x=x/2;
            k++;
        }
        k=0;
        while(y>0)
        {
            if(y%2==1)
            {
                if(st.count(k))st.erase(k);
                else
                ans++;
            }
            y=y/2;
            k++;
        }

        return ans+st.size();
        
    }
};