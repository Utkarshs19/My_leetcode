class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {

        map<int,int> m1;
        int ans=0;
        int i=0,j=0;

        while(j<arrivals.size())
        {
            m1[arrivals[j]]++;
            if(m1[arrivals[j]]>m)
            {
                ans++;
                m1[arrivals[j]]--;
                arrivals[j]=-1;
            }

            if(j-i+1==w)
            {
                if(arrivals[i]<0)
                {
                    i++;
                }
                else{
                m1[arrivals[i]]--;
                i++;
                }
            }

            j++;
        }

        return ans;
        
    }
};