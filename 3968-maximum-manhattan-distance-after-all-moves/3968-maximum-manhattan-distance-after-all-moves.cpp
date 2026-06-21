class Solution {
public:
    int maxDistance(string moves) {

        int x=0,y=0,z=0;

        for(auto i:moves)
        {
            if(i=='_')z++;
            else if(i=='R')x++;
            else if(i=='L')x--;
            else if(i=='U')y++;
            else if(i=='D')y--;
        }
        
        return abs(x)+abs(y)+z;
    }
};