class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {

        vector<vector<string>> ans;
        int n=words.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && words[i][0]==words[j][0])
                for(int a=0;a<n;a++)
                {
                    if(i!=a && j!=a && words[i].back()==words[a][0])
                    for(int b=0;b<n;b++)
                    {
                        if(i!=b && j!=b && a!=b && words[j].back()==words[b][0] && words[a].back()==words[b].back())
                        ans.push_back({words[i],words[j],words[a],words[b]});
                    }
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};