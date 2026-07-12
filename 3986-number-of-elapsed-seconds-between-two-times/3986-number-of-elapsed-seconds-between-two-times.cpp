class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {

        int seconds1=0;
        int seconds2=0;

        int h1=stoi(startTime.substr(0,2));
        int m1=stoi(startTime.substr(3,2));
        int s1=stoi(startTime.substr(6));
        
        seconds1+=(h1*3600);
        seconds1+=(m1*60);
        seconds1+=s1;

        int h2=stoi(endTime.substr(0,2));
        int m2=stoi(endTime.substr(3,2));
        int s2=stoi(endTime.substr(6));
        
        seconds2+=(h2*3600);
        seconds2+=(m2*60);
        seconds2+=s2;

        return seconds2-seconds1;


    }
};