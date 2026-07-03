class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        int i=0,j=0;
        int start=0,end=INT_MAX;
        vector<vector<int>> ans;
        while(i<firstList.size() && j<secondList.size())
        {
            start=max(firstList[i][0],secondList[j][0]);
            end=min(firstList[i][1],secondList[j][1]);

            if(start<=end)
            ans.push_back({start,end});

            if(end==firstList[i][1])i++;
            if(end==secondList[j][1])j++;
           
        }
        return ans;
        
    }
};