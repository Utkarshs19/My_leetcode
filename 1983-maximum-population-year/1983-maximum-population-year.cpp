class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        map<int,int> m;

        for(int i=0;i<logs.size();i++)
        {
            for(int j=logs[i][0];j<logs[i][1];j++)
            {
                m[j]++;
            }
        }


        int f=0;

        for(auto i:m)
        {
            f=max(f,i.second);
        }

        for(auto i:m)
        {
            if(i.second==f)return i.first;
        }

        return 0;
        
    }
};