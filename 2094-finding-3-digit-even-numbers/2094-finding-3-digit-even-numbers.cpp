class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        vector<int> ans;
        map<int,int> m;
        for(auto i:digits)
        {
            m[i]++;
        }

        for(int i=100;i<=999;i++)
        {
            if(i%2==1)continue;
            int x=i;
            vector<int> v(10,0);
            while(x>0)
            {
                v[x%10]++;
                x=x/10;
            }
            bool flag=true;
            for(int i=0;i<10;i++)
            {
                if(v[i]>0 && m[i]<v[i])flag=false;
            }
            if(flag)ans.push_back(i);
        }
        
        return ans;
        
    }
};