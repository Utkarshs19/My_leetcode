class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {

        int ans=1e9;

        for(int i=0;i<words.size();i++)
        {
            if(words[i]==target)
            {
                int x=abs(i-startIndex);
                ans=min(ans,x);
                ans=min(ans,(int)(words.size()-x));
            }
        }

        return ans==1e9?-1:ans;
        
    }
};