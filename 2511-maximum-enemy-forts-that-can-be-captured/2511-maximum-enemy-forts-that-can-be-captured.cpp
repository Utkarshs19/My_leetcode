class Solution {
public:
    int captureForts(vector<int>& forts) {

        int ans=0;

        int minus=-1;
        int one=-1;

        for(int i=0;i<forts.size();i++)
        {
            if(forts[i]==0)continue;
            else if(forts[i]==1)
            {
                
                if(minus!=-1 && minus>one)
                {
                    ans=max(ans,i-minus-1);
                }
                one=i;
            }
            else if(forts[i]==-1)
            {
                
                if(one!=-1 && one>minus)
                {
                    ans=max(ans,i-one-1);
                }
                minus=i;
            }
        }

        return ans;
        
    }
};