class Solution {
public:
    int minimumDeletions(string word, int k) {

        map<char,int> m;

        for(int i=0;i<word.length();i++)
        {
            m[word[i]]++;
        }

        int ans=INT_MAX;

        for(auto i:m)
        {
            int x=i.second;
            int cnt=0;
            for(auto j:m)
            {
                int y=j.second;

                if(x>y)
                cnt+=y;
                else if(y>x+k)
                cnt+=(y-(x+k));
            }
            ans=min(ans,cnt);
        
        }

        return ans;
        
    }
};