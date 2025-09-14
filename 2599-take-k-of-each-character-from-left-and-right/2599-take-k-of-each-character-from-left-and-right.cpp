class Solution {
public:
    int takeCharacters(string s, int k) {

        vector<int> v(3,0);

        for(char c:s)
        {
            v[c-'a']++;
        }

        if(v[0]<k)return -1;

        if(v[1]<k)return -1;

        if(v[2]<k)return -1;


        int l=0;

        int maxi=0;

        for(int r=0;r<s.length();r++)
        {
            v[s[r]-'a']--;

            while(l<=r && v[0]<k||v[1]<k||v[2]<k)
            {
                v[s[l]-'a']++;
                l++;
            }

            maxi=max(maxi,r-l+1);
        }

        return s.length()-maxi;


        
    }
};