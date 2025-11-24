class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            m[(arr[i]%k + k)%k]++;
        }



        if(m.find(0)!=m.end())
        {
            if(m[0]%2!=0)return false;
        }
        m.erase(0);

        if(k%2==0)
        {
            if(m.find(k/2)!=m.end())
            {
                if(m[k/2]%2!=0)return false;
            }
            m.erase(k/2);
        }

        for(auto i:m)
        {
            if(m.find(k-i.first)!=m.end())
            {
                if(m[i.first]!=m[k-i.first])return false;
            }
        }

        return true;


        
    }
};