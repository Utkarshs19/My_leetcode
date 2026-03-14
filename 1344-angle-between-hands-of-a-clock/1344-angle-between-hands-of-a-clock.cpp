class Solution {
public:
    double angleClock(int hour, int minutes) {

        if(hour==12)hour=0;

        double m=6*minutes;
        double h=30*hour+0.5*minutes;

        double x=abs(h-m);

        return min(x,360-x);
        
    }
};