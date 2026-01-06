class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        map<int,int> m;

        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        int ans=0;

        for(auto i:m)
        {
            int x=0;
            x=i.second/3;

            if(i.second%3==0)
            {
                ans+=x;
            }
            else
            {
                if(i.second%3==1)
                {
                    if(x>0)
                    {
                        ans+=x-1;
                        ans+=2;
                    }
                    else return -1;
                }
                if(i.second%3==2)
                {
                    ans+=x;
                    ans++;
                }
            }
        }

        return ans;
        
    }
};