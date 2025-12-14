class Solution {
public:
    long long minMoves(vector<int>& balance) {

        long long ans=0;
        int n=balance.size();
        long long sum=accumulate(balance.begin(),balance.end(),0LL);
        if(sum<0)return -1;

        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(balance[i]<0){
                idx=i;
                break;
            }
        }

        if(idx==-1)return 0;

        long long val=-balance[idx];

        for(int i=1;i<n && val>0;i++)
        {
            int l=(idx-i+n)%n;
            int r=(idx+i)%n;

            if(balance[l]>0 && val>0)
            {
                long long pick=min((long long)balance[l],val);
                ans+=pick*i;
                val-=pick;
                balance[l]-=pick;
            }
            if(balance[r]>0 && val>0)
            {
                long long pick=min((long long)balance[r],val);
                ans+=pick*i;
                val-=pick;
                balance[r]-=pick;

            }
        }
        
        return ans;
        
    }
};