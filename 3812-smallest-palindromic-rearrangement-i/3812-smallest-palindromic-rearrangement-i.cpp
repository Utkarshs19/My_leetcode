class Solution {
public:
    string smallestPalindrome(string s) {

        string ans=s;

        map<char,int> m;

        for(auto i:s)
        {
            m[i]++;
        }

        int k=0;
        int j=s.length()-1;

        for(auto i:m)
        {
            int cnt=i.second;

            cnt=cnt/2;

            while(cnt>0)
            {
                ans[k]=i.first;
                k++;
                ans[j]=i.first;
                j--;
                cnt--;
            }

        }
        
        return ans;
        
    }
};