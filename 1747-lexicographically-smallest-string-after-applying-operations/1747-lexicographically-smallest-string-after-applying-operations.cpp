class Solution {
public:
    string add(string s,int a)
    {
        for(int i=1;i<s.length();i+=2)
        {
            s[i]=((s[i]-'0'+a)%10)+'0';
        }

        return s;
    }

    string rotate(string s,int b)
    {
        int n=s.length();
        int shift=b%n;

        return s.substr(n-shift)+s.substr(0,n-shift);
    }
    string findLexSmallestString(string s, int a, int b) {

        unordered_set<string> vis;

        queue<string> q;

        q.push(s);

        string ans=s;

        while(!q.empty())
        {
            string cur = q.front();
            q.pop();

            if (vis.count(cur)) continue;
            vis.insert(cur);
            ans = min(ans, cur);

            // Apply both operations
            string added = add(cur,a);
            string rotated = rotate(cur,b);

            if (!vis.count(added)) q.push(added);
            if (!vis.count(rotated)) q.push(rotated);

        }
        return ans;        
    }
};