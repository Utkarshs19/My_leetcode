class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

        map<int,vector<pair<int,int>>> m;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                m[abs(rCenter-i)+abs(cCenter-j)].push_back({i,j});
            }
        }

        vector<vector<int>> v;

        int i=0,j=0;
        for(auto i:m)
        {
            vector<pair<int,int>> x=i.second;
            for(int k=0;k<x.size();k++)
            {
                vector<int> a;
                a.push_back(x[k].first);
                a.push_back(x[k].second);
                v.push_back(a);
            }
        }
        return v;
        
    }
};