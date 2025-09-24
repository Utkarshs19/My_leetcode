class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {

        int ans=0;

        int k=0;


        if(rungs[0]>dist)
        {
            if(rungs[0]%dist==0)
            ans+=(rungs[0]/dist)-1;
            else
            ans+=(rungs[0]/dist);
        }

        for(int i=1;i<rungs.size();i++)
        {
            if(rungs[i]-rungs[i-1]>dist)
            {   
                if(((rungs[i]-rungs[i-1])%dist)==0)
                ans+=((rungs[i]-rungs[i-1])/dist)-1;
                else
                ans+=((rungs[i]-rungs[i-1])/dist);
            }
            
        }

        return ans;

        
    }
};