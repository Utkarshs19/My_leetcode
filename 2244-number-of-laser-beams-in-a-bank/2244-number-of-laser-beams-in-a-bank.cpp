class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int ans=0;
        int prev=0;
        int cur=0;
        int i=0;

        while(prev<=0)
        {   
            for(i=0;i<bank.size();i++)
            {
                for(int j=0;j<bank[i].length();j++)
                {
                    if(bank[i][j]=='1')
                    prev++;             
                }
                cout<<endl;
                if(prev>0)break;
            }

            if(i==bank.size())
            return ans;
        }
        i++;

        for(i;i<bank.size();i++)
        {
            
                for(int j=0;j<bank[i].length();j++)
                {
                    if(bank[i][j]=='1')
                    cur++;
                }

                if(cur==0)
                continue;

              cout<<prev<<"  "<<cur<<endl;

            ans+=(cur * prev);
            prev=cur;
            cur=0;
        }
        
        return ans;
    }
};