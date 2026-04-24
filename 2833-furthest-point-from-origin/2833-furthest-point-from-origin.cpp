class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
         int x=0,y=0;
        for(auto it:moves){
            if(it=='L')x++,y--;
            else if(it=='R')y++,x--;
            else x++,y++;
        }
        return max(x,y);
    }
};