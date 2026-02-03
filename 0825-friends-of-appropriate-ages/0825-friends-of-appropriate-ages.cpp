class Solution {
public:

    bool helper(int x,int y)
    {
        return !(y<=(0.5*x+7) || y>x ||( y>100 && x<100));
    }

    int numFriendRequests(vector<int>& ages) {

        map<int,int> m;

        for(auto i:ages)
        m[i]++;

        int ans=0;

        for(auto i:m)
        {
            for(auto j:m)
            {
                if(helper(i.first,j.first))
                {
                    ans+=(i.second*(j.second-(i.first==j.first?1:0)));
                }
            }
        }

        return ans;
        
    }
};