class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {

        int sum=0,cnt=0;
        int j=0;

        for(int i=0;i<s.length();i++)
        {
            sum+=widths[s[i]-'a'];
            if(sum>100)
            {
                cnt++;
                sum=0;
                j=i;
                i--;
                cout<<j<<endl;
            }
        }
        
        sum=0;
        
        for(int i=j;i<s.length();i++)
        {
            sum+=widths[s[i]-'a'];
        }

        return {cnt+1,sum};

    }
};