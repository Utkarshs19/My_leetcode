class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {

        int idx=-1;
        int ans=0;
        int mini;

        while(arr.size()>1)
        {
            vector<int> v=arr;
            idx=-1;
            mini=1e9;
            for(int i=1;i<v.size();i++)
            {
                if(mini>(v[i-1]*v[i]))
                {
                    mini=v[i-1]*v[i];
                    idx=i-1;
                }
            }

            ans+=mini;
            arr.clear();
            for(int i=0;i<idx;i++)
            {
                arr.push_back(v[i]);
            }
            arr.push_back(max(v[idx],v[idx+1]));
            for(int i=idx+2;i<v.size();i++)
            {
                arr.push_back(v[i]);
            }
        }
        return ans;
    }
};