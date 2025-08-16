class Solution {
public:
    bool canAliceWin(int n) {
        
        bool flag=true;
        int cnt=10;

        while(cnt<=n)
        {
            n=n-cnt;
            cnt--;
            flag=!flag;
        }

        return !flag;
    

    }
};