class Solution {
public:
    int maxRepeating(string sequence, string word) {
        
        int ans=0;

        int l=word.length();

        for(int i=0;i<sequence.length();i++)
        {
            int cnt=0;
            if(sequence.substr(i,l)==word)
            {   
                 cnt=1;
                for(int j=i+l;j<sequence.length();j+=l)
                {
                    if(sequence.substr(j,l)==word)cnt++;
                    else break;
                }
            }
            ans=max(ans,cnt);
        }

        return ans;

    }
};