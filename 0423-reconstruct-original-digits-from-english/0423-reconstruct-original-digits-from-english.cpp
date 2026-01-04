class Solution {
public:
    string originalDigits(string s) {

        map<char,int> m;
        for(char c : s) m[c]++;

        string ans="";

        // zero
        while(m['z'] > 0) {
            ans+='0';
            m['z']--; m['e']--; m['r']--; m['o']--;
        }

        // two
        while(m['w'] > 0) {
            ans+='2';
            m['t']--; m['w']--; m['o']--;
        }

        // four
        while(m['u'] > 0) {
            ans+='4';
            m['f']--; m['o']--; m['u']--; m['r']--;
        }

        // six
        while(m['x'] > 0) {
            ans+='6';
            m['s']--; m['i']--; m['x']--;
        }

        // eight
        while(m['g'] > 0) {
            ans+='8';
            m['e']--; m['i']--; m['g']--; m['h']--; m['t']--;
        }

        // one
        while(m['o'] > 0) {
            ans+='1';
            m['o']--; m['n']--; m['e']--;
        }

        // three
        while(m['h'] > 0) {
            ans+='3';
            m['t']--; m['h']--; m['r']--; m['e'] -= 2;
        }

        // five
        while(m['f'] > 0) {
            ans+='5';
            m['f']--; m['i']--; m['v']--; m['e']--;
        }

        // seven
        while(m['s'] > 0) {
            ans+='7';
            m['s']--; m['e'] -= 2; m['v']--; m['n']--;
        }

        // nine
        while(m['i'] > 0) {
            ans+='9';
            m['n'] -= 2; m['i']--; m['e']--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
