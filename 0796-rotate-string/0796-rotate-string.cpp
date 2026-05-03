class Solution {
public:
    bool rotateString(string s, string goal) {

        int i=0;

        while(i<s.length())
        {
            string str=s.substr(i);
            str+=s.substr(0,i);

            if(str==goal)return true;
            i++;
        }

        return false;
        
    }
};