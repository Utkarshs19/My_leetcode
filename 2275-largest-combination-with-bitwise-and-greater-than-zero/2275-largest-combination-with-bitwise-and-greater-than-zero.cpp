class Solution {
public:
    map<int,int> m;

    void binary(int x)
    {
        int k=0;
        while(x>0)
        {
            if(x%2==1)m[k]++;
            x=x/2;
            k++;
        }

    }

    int largestCombination(vector<int>& candidates) {

        for(int i=0;i<candidates.size();i++)
        {
            binary(candidates[i]);
        }

        int ans=0;
        
        for(auto i:m)
        {
            ans=max(ans,(int)(i.second));
        }

        return ans;
    }
};