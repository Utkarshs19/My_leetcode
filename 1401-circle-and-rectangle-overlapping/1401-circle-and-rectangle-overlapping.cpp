class Solution {
public:
    int helper(int x,int y)
    {
        return (x-y)*(x-y);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                if((helper(xCenter,i))+helper(yCenter,j) <=(radius*radius))return true;
            }
        }
        return false;
        
    }
};