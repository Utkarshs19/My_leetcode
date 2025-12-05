class Solution {
public:
    int x;
    bool helper(string str)
    {
        long long n=0;

        for(int i=0;i<str.length();i++)
        {
            n=n*10+(str[i]-'0');
        }
        if(n==0)return false;
        return (x%n==0);
    }

    int divisorSubstrings(int num, int k) {

        x=num;
        string s=to_string(num);

        int i=0,j=0;

        int n=s.length();
        int ans=0;

        while(j<n)
        {
            if(j-i+1<k)
            j++;
            else if(j-i+1==k)
            {
                if(helper(s.substr(i,k)))ans++;

                i++;

            }
        }

        return ans;
        
    }
};