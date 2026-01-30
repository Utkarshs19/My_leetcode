class Solution {
public:
    bool isRobotBounded(string instructions) {

        int x=0,y=0;
        char dir='N';

        for(int i=0;i<instructions.size();i++)
        {
            if(instructions[i]=='G' && dir=='N')
            {
                y=y+1;
            }
            else if(instructions[i]=='L' && dir=='N')
            {
                dir='W';
            }
            else if(instructions[i]=='R' && dir=='N')
            {
                dir='E';
            }
            else if(instructions[i]=='G' && dir=='S')
            {
                y=y-1;
            }
             else if(instructions[i]=='L' && dir=='S')
            {
                dir='E';
            }
             else if(instructions[i]=='R' && dir=='S')
            {
                dir='W';
            }
             else if(instructions[i]=='G' && dir=='E')
            {
                x=x+1;
            }
             else if(instructions[i]=='L' && dir=='E')
            {
                dir='N';
            }
             else if(instructions[i]=='R' && dir=='E')
            {
                dir='S';
            }
             else if(instructions[i]=='G' && dir=='W')
            {
                x=x-1;
            }
             else if(instructions[i]=='L' && dir=='W')
            {
                dir='S';
            }
             else if(instructions[i]=='R' && dir=='W')
            {
                dir='N';
            }
        }

        if(dir!='N' || (x==0 && y==0))return true;
        return false;
        
    }
};