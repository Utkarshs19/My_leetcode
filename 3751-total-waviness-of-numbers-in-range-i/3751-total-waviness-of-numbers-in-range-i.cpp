class Solution {
public:

    int helper(int x)
    {
        int ans=0;

        string str=to_string(x);

        if(str.length()<3)return 0;

        for(int i=1;i<str.length()-1;i++)
        {
if((str[i]>str[i-1] && str[i]>str[i+1])  || (str[i]<str[i-1]&& str[i]<str[i+1]))
            ans++;
        }


        return ans;
    }

    int totalWaviness(int num1, int num2) {

        int ans=0;

        while(num1<=num2)
        {
            ans+=helper(num1);
            num1++;
        }

        return ans;
        
    }
};