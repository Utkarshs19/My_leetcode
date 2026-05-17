class Solution {
public:
    int countKthRoots(int l, int r, int k) {

        int x=0;
        int ans=0;
        if(k==1)return r-l+1;
        while(true)
        {
            int y=pow(x,k);
            if(y>r)break;

            if(y>=l && y<=r)ans++;
            x++;
        }

        return ans;
    }
};