class Solution {
public:
    int minimumKeypresses(string s) {

        map<char,int> m;

        for(auto i:s)
        {
            m[i]++;
        }

        vector<int> v;

        for(auto i:m)
        {
            v.push_back(i.second);
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<"  ";
            ans+=((i/9)+1)*v[i];
            cout<<ans<<endl;
        }

        return ans;
    }
};