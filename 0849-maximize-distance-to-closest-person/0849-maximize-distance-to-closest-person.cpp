class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int pos=-1;

        
        int ans=INT_MIN;

        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1)
            {
                if(pos==-1)
                ans=max(ans,i);
                else
                {
                    ans=max(ans,(i-pos)/2);
                }
                pos=i;
            }
        }

       return ans>=seats.size()-1-pos?ans:seats.size()-1-pos;

    }
};