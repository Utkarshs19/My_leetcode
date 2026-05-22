class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {

        vector<int> v1=arrays[0];

        vector<int> v;

        for(int k=1;k<arrays.size();k++)
        {
            vector<int> v2=arrays[k];
            v.clear();

            int i=0,j=0;

            while(i<v1.size() && j<v2.size())
            {
                if(v1[i]==v2[j])
                {
                    v.push_back(v1[i]);
                    i++;
                    j++;
                }
                else if(v1[i]<v2[j])i++;
                else
                j++;
            }

            v1=v;
        }

        return v1;
        
    }
};