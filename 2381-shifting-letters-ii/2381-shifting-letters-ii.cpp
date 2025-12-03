class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n=s.length();

        vector<int> diff(n+1,0);

        for(int i=0;i<shifts.size();i++)
        {
            int l=shifts[i][0];
            int r=shifts[i][1];
            int d=shifts[i][2];

            if(d==1)
            {
                diff[l]+=1;
                if(r+1<n)
                diff[r+1]-=1;
            }
            else
            {
                diff[l]+=-1;
                if(r+1<n)
                diff[r+1]+=1;
            }
        }

        vector<int> pre(n,0);

        pre[0]=diff[0];

        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+diff[i];
        }

        


        for(int i=0;i<n;i++)
        {
            int shift = (pre[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
        
    }
};