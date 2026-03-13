class Solution {
public:
    int maxVowels(string s, int k) {

        int ans=0;
        int cnt=0;
        int i=0,j=0;

        while(j<s.length())
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u')
            cnt++;

            if(j-i+1==k)
            {
                ans=max(ans,cnt);
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                cnt--;

                i++;
            }
            j++;
        }

        return ans;
        
    }
};