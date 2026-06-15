class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        
        int n=encoded1.size(),m=encoded2.size();

        vector<vector<int>> ans;
        int i=0,j=0;
        int mini=INT_MAX;

        while(i<n && j<m)
        {
            int mini=min(encoded1[i][1],encoded2[j][1]);

            int x=encoded1[i][0]*encoded2[j][0];

            if(ans.size()>0){
                
                if(ans.back()[0]==x)
                    ans.back()[1]+=mini;
                else
                ans.push_back({x,mini});
            }
            else
            {
                ans.push_back({x,mini});
            }
            encoded1[i][1]-=mini;
            encoded2[j][1]-=mini;

            if(encoded1[i][1]==0)i++;
            if(encoded2[j][1]==0)j++;
        }

        return ans;

    }
};