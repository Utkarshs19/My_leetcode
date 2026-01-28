class Solution {
public:
    int clumsy(int n) {

        vector<int> v;
        int x=0;
        while(n>0)
        {
            if(x==1 || x==2)
            {
                
                    int y=v[v.size()-1];
                    v.pop_back();
                    if(x==1)
                    v.push_back(y*n);
                    else if(x==2)
                    {
                        v.push_back(y/n);
                    }
                
            }
            else
            v.push_back(n);
            x++;
            n--;
            if(x==4)x=0;

        }
        int ans=v[0];
        bool flag=true;
        for(int i=1;i<v.size();i++)
        {
            if(flag)ans+=v[i];
            else
            ans-=v[i];
            flag=!flag;
        }

        return ans;



        
    }
};