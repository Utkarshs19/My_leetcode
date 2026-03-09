class Solution {
public:
    vector<string> ans;
    string s;
    long long x;
    long long a;

    void helper(int i,string &num,int &target)
    {
        if(i==num.length())
        {
            if(x==target)
                ans.push_back(s);
            return;
        }

        long long y = 0;

        for(int j=i;j<num.length();j++)
        {
            if(j>i && num[i]=='0') break;

            y = y*10 + (num[j]-'0');
            string t = num.substr(i,j-i+1);

            long long oldx = x;
            long long olda = a;

            // +
            s += "+";
            s += t;
            x = oldx + y;
            a = y;
            helper(j+1,num,target);
            s.erase(s.size()-t.size()-1);
            x = oldx;
            a = olda;

            // -
            s += "-";
            s += t;
            x = oldx - y;
            a = -y;
            helper(j+1,num,target);
            s.erase(s.size()-t.size()-1);
            x = oldx;
            a = olda;

            // *
            s += "*";
            s += t;
            x = oldx - olda + olda*y;
            a = olda*y;
            helper(j+1,num,target);
            s.erase(s.size()-t.size()-1);
            x = oldx;
            a = olda;
        }
    }

    vector<string> addOperators(string num, int target) {

        long long y = 0;

        for(int i=0;i<num.length();i++)
        {
            if(i>0 && num[0]=='0') break;

            y = y*10 + (num[i]-'0');

            s = num.substr(0,i+1);
            x = y;
            a = y;

            helper(i+1,num,target);
        }

        return ans;
    }
};