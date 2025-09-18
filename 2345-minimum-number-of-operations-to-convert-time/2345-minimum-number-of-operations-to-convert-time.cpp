class Solution {
public:
    int convertTime(string current, string correct) {
        
        int time1=stoi(current.substr(0,2))*60+stoi(current.substr(3));

        int time2=stoi(correct.substr(0,2))*60+stoi(correct.substr(3));

        int diff = time2-time1;
        int ops[4] = {60,15,5,1}, ans = 0;
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }
};