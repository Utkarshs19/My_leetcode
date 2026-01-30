class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {

        map<int,int> m1;
        for(int i=1;i<=m;i++)
        {
            m1[i]=i-1;
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++)
        {
            ans.push_back(m1[queries[i]]);

            int pos=m1[queries[i]];

            for(auto j:m1)
            {
                if(j.second<pos)
                {
                    m1[j.first]=j.second+1;
                }
            }

            m1[queries[i]]=0;

        }
        

        return ans;
    }
};