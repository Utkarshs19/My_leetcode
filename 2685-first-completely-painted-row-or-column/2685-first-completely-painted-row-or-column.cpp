class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        map<int,pair<int,int>> m;

        map<int,int> row;
        map<int,int> col;

        int a=mat.size();
        int b=mat[0].size();

         for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                
                m[mat[i][j]]={i,j};

            }
        }

        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i])!=m.end())
            {
                int x = m[arr[i]].first;
                int y = m[arr[i]].second;

                cout<<x<<" "<<y<<endl;

                row[x]++;
                if(row[x]==b)return i;
                col[y]++;
                if(col[y]==a)return i;
            }
        }
        

        return -1;
    }
};