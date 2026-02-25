class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        map<int,vector<int>> m;
        
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i];
            int cnt=0;
            while(x>0)
            {
                if(x%2==1)cnt++;
                x=x/2;
            }
            m[cnt].push_back(arr[i]);
        }
        vector<int> ans;
        for(auto i:m)
        {
            vector<int> v=i.second;
            sort(v.begin(),v.end());
            for(int j=0;j<v.size();j++)
            {
                ans.push_back(v[j]);
            }
        }
        
        return ans;
    }
};