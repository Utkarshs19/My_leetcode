class Solution {
public:
    int minNumberOperations(vector<int>& target) {

        int ans=0;
        int prev=0;
        for(int i=0;i<target.size();i++)
        {
            if(target[i]>prev)
            ans+=target[i]-prev;

            prev=target[i];
        }

        return ans;
        
    }
};